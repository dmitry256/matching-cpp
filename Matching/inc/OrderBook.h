#include "spdlog/spdlog.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <vector>

namespace matching_engine {

using Price = double;
using Time = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Time>;
using UUID = std::string;

enum SIDE { BUY, SELL };

enum STATE { INACTIVE, ACTIVE, CANCELLED, FULFILLED };

enum TIF { GTC };

std::atomic<double> total_turnover{0.0};

class Order {
public:
  Order(const std::string &uuid, const Price &price, const Price &quantity,
        const SIDE &side, const STATE &state = STATE::INACTIVE,
        const TIF &tif = TIF::GTC, const Price &executed_quantity = 0,
        const TimePoint &created = Time::now())
      : uuid_{uuid}, price_{price}, quantity_{quantity},
        executed_quantity_{executed_quantity}, side_{side}, state_{state},
        tif_{tif}, created_{created}, leftover_{quantity_ -
                                                executed_quantity_} {}
  Order() = delete;
  Order(const Order &) = delete;
  ~Order() = default;
  Price quantity() const { return quantity_; }
  Price price() const { return price_; }
  SIDE side() const { return side_; }
  void execute(const Price &quantity) {
    executed_quantity_ += quantity;
    leftover_ = quantity_ - executed_quantity_;
  }
  Price leftover() const { return leftover_; }
  TIF tif() const { return tif_; }
  void state(STATE state) {
    state_ = state;
    if (state == STATE::FULFILLED) {
      auto v = total_turnover.load();
      while (!total_turnover.compare_exchange_weak(v, v + quantity_))
        ;
    }
  }
  /* Price/Time priority */
  bool operator>=(const Order &rhs) const {
    return side_ == rhs.side_ && price_ == rhs.price_ &&
           created_ <= rhs.created_ && quantity_ >= rhs.quantity_;
  }
  bool operator==(const Order &rhs) const {
    return uuid_ == rhs.uuid_ && side_ == rhs.side_ && price_ == rhs.price_ &&
           quantity_ == rhs.quantity_;
  }
  friend std::ostream &operator<<(std::ostream &out, const Order &o) {
    return out << "Created: " << o.created_.time_since_epoch().count()
               << " , UUID: " << o.uuid_ << ", Side: " << o.side_
               << ", State: " << o.state_ << ", Price: " << o.price_
               << " Quantity: " << o.quantity_
               << ", Executed:  " << o.executed_quantity_
               << ", Leftover: " << o.leftover_;
  }

private:
  const UUID uuid_;
  const Price price_;
  const double quantity_;
  double executed_quantity_;
  const SIDE side_;
  STATE state_;
  TIF tif_;
  const TimePoint created_;
  double leftover_;
};

typedef cds::container::BasketQueue<
    cds::gc::HP, Order,
    typename cds::container::basket_queue::make_traits<
        cds::opt::item_counter<cds::atomicity::item_counter>>::type>
    basket_queue;

class OrderQueue {
private:
  basket_queue q;

public:
  OrderQueue(const OrderQueue &) = delete;
  OrderQueue() = default;
  ~OrderQueue() = default;

  bool remove(std::shared_ptr<Order> &order) {
    auto o =
        std::find_if(begin(c), end(c), [&](auto &&it) { return it == order; });
    if (o != end(c)) {
      c.erase(o, end(c));
      return true;
    }
    return false;
  }
  Price accumulate() const {
    return std::accumulate(begin(c), end(c), 0.0,
                           [](const Price amount, const auto &it) {
                             return amount + it->leftover();
                           });
  }
};

class OrderBook {
private:
  struct Comp {
    enum compare_type { less, greater };
    explicit Comp(compare_type t) : type(t) {}
    template <class T, class U> bool operator()(const T &t, const U &u) const {
      return type == less ? t < u : t > u;
    }
    compare_type type;
  };
  std::shared_ptr<spdlog::logger> logger_;

public:
  using OrderTree = std::map<Price, OrderQueue, Comp>;
  OrderTree buy_tree_;
  OrderTree sell_tree_;
  OrderBook(const OrderBook &) = delete;
  OrderBook(std::shared_ptr<spdlog::logger> &logger)
      : logger_{logger}, buy_tree_{Comp{Comp::greater}}, sell_tree_{Comp{
                                                             Comp::less}} {}
  ~OrderBook() = default;

  bool cancel(std::shared_ptr<Order> &order) {
    auto &tree = order->side() == SIDE::BUY ? buy_tree_ : sell_tree_;
    try {
      auto &&order_queue = tree.at(order->price());
      auto result = order_queue.remove(order);
      order->state(STATE::CANCELLED);
      if (order_queue.empty()) /* Drop price node */
        tree.erase(order->price());
      return result;
    } catch (const std::out_of_range &) { /* No price point exist */
      return false;
    }
  }

  bool match(std::shared_ptr<Order> &src) {
    auto &dist_tree = src->side() == SIDE::BUY ? sell_tree_ : buy_tree_;
    auto &src_tree = src->side() == SIDE::BUY ? buy_tree_ : sell_tree_;
    src->state(STATE::ACTIVE);

    bool exit_tree = false;
    bool exit_queue = false;
    for (auto node = begin(dist_tree); !exit_tree && node != end(dist_tree);) {
      auto &&dist_queue = node->second;
      /* Buy cheap; sell expensive – conduct price improvement */
      if (src->side() == SIDE::BUY ? src->price() >= node->first
                                   : src->price() <= node->first) {
        while (!exit_queue && !dist_queue.empty()) {
          auto &dist = dist_queue.top();
          auto leftover = dist->leftover() - src->leftover();

          /* Fulfilled source; partially or fulfilled dist */
          if (leftover >= 0) {
            src->execute(src->leftover());
            src->state(STATE::FULFILLED);

            if (leftover == 0) /* Exact match */
              dist->execute(dist->leftover());
            else /* Partial match */
              dist->execute(dist->leftover() - leftover);

            /* Remove fulfilled order from queue */
            if (dist->leftover() == 0) {
              dist->state(STATE::FULFILLED);
              dist_queue.pop();
            }

            /* Matching is complete */
            exit_queue = true;
            exit_tree = true;
          }
          /* Partially-filled source; fulfilled dist */
          else {
            src->execute(dist->leftover());
            dist->execute(dist->leftover());
            dist->state(STATE::FULFILLED);
            dist_queue.pop();
            /* Try next order in the queue */
          }
        }
        /* Try next price node */
        if (dist_queue.empty()) { /* Purge the price point with empty queue */
          node = dist_tree.erase(node++);
        } else {
          ++node;
        }
      } else {
        exit_tree = true;
      }
    }
    /* Not enough resources to fulfill the order; push to source tree */
    if (src->leftover() > 0) {
      const auto &found = src_tree.find(src->price());
      if (found == src_tree.end()) { /* Create new price node */
        const auto &inserted = src_tree.insert(
            found,
            std::move(std::make_pair(src->price(), std::move(OrderQueue()))));
        inserted->second.push(src);
      } else { /* Insert in existing price node */
        found->second.push(src);
      }
      return false;
    }
    /* Order's been fulfilled */
    return true;
  }

  Price best_buy() const {
    return !buy_tree_.empty() ? begin(buy_tree_)->first : 0;
  }

  Price best_sell() const {
    return !sell_tree_.empty() ? begin(sell_tree_)->first : 0;
  }

  Price quote() const { return (best_buy() + best_sell()) / 2; }

  Price spread() const {
    auto buy = best_buy();
    auto sell = best_sell();
    return buy && sell ? (sell - buy) / sell : 0;
  }

  void print_summary() const {
    auto print = [this](const auto &tree) {
      Price side_volume = 0.0;
      unsigned long size = 0;
      for (auto &&node : tree) {
        auto &&price_node = node.first;
        auto &&order_queue = node.second;
        auto &&queue_volume = order_queue.accumulate();
        side_volume += queue_volume;
        size += order_queue.size();
        printf("|%-8.4f|%13.2f|%10lu|\n", price_node, queue_volume,
               order_queue.size());
      }
      return std::make_tuple(side_volume, size);
    };

    auto turnover = total_turnover.load();
    std::cout << "\033[2J\033[1;1H";
    printf("\n\n============ Order Book ============\n\n");
    printf("-----------------------------------\n");
    printf("|%-8s|%13s|%10s|\n", "", "", "");
    printf("|%-8s|%13s|%10s|\n", "Price", "Volume", "Size");
    printf("|%-8s|%13s|%10s|\n", "", "", "");
    printf("|--------------- Buy -------------|\n");
    printf("|%-8s|%13s|%10s|\n", "", "", "");
    auto [buy_vol, buy_size] = print(buy_tree_);
    printf("|%-8s|%13s|%10s|\n", "", "", "");
    printf("|--------------- Sell ------------|\n");
    printf("|%-8s|%13s|%10s|\n", "", "", "");
    auto [sell_vol, sell_size] = print(sell_tree_);
    printf("-----------------------------------\n");
    printf("\n\n========== Trading summary =========\n\n");
    printf("-----------------------------------\n");
    printf("|%-16s|%16.2f|\n", "Buy volume", buy_vol);
    printf("|%-16s|%16.2f|\n", "Sell volume", sell_vol);
    printf("|%-16s|%16.4f|\n", "Best bid", best_buy());
    printf("|%-16s|%16.4f|\n", "Best ask", best_sell());
    printf("|%-16s|%16.4f|\n", "Quote", quote());
    printf("|%-16s|%15.2f%%|\n", "Spread", spread() * 100);
    printf("|%-16s|%16.2f|\n", "Turnover", turnover);
    printf("|%-16s|%16.2f|\n", "Commission", turnover * 0.002);
    printf("|%-16s|%16.lu|\n", "Order book size", buy_size + sell_size);
    printf("-----------------------------------\n");
  }
};
} // namespace matching_engine
