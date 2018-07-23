// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: orderbook.proto

#include "orderbook.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_shared_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_shared_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_PricePointProto;
extern PROTOBUF_INTERNAL_EXPORT_protobuf_shared_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_SpreadProto;
}  // namespace protobuf_shared_2eproto
namespace proto {
class OrderBookProtoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<OrderBookProto>
      _instance;
} _OrderBookProto_default_instance_;
}  // namespace proto
namespace protobuf_orderbook_2eproto {
static void InitDefaultsOrderBookProto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::proto::_OrderBookProto_default_instance_;
    new (ptr) ::proto::OrderBookProto();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::proto::OrderBookProto::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<2> scc_info_OrderBookProto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsOrderBookProto}, {
      &protobuf_shared_2eproto::scc_info_SpreadProto.base,
      &protobuf_shared_2eproto::scc_info_PricePointProto.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_OrderBookProto.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto::OrderBookProto, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto::OrderBookProto, market_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto::OrderBookProto, size_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto::OrderBookProto, spread_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto::OrderBookProto, points_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::proto::OrderBookProto)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::proto::_OrderBookProto_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "orderbook.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\017orderbook.proto\022\005proto\032\014shared.proto\"z"
      "\n\016OrderBookProto\022\016\n\006market\030\001 \001(\t\022\014\n\004size"
      "\030\002 \001(\004\022\"\n\006spread\030\003 \001(\0132\022.proto.SpreadPro"
      "to\022&\n\006points\030\004 \003(\0132\026.proto.PricePointPro"
      "tob\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 170);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "orderbook.proto", &protobuf_RegisterTypes);
  ::protobuf_shared_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_orderbook_2eproto
namespace proto {

// ===================================================================

void OrderBookProto::InitAsDefaultInstance() {
  ::proto::_OrderBookProto_default_instance_._instance.get_mutable()->spread_ = const_cast< ::proto::SpreadProto*>(
      ::proto::SpreadProto::internal_default_instance());
}
void OrderBookProto::clear_spread() {
  if (GetArenaNoVirtual() == NULL && spread_ != NULL) {
    delete spread_;
  }
  spread_ = NULL;
}
void OrderBookProto::clear_points() {
  points_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int OrderBookProto::kMarketFieldNumber;
const int OrderBookProto::kSizeFieldNumber;
const int OrderBookProto::kSpreadFieldNumber;
const int OrderBookProto::kPointsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

OrderBookProto::OrderBookProto()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_orderbook_2eproto::scc_info_OrderBookProto.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto.OrderBookProto)
}
OrderBookProto::OrderBookProto(const OrderBookProto& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      points_(from.points_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  market_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.market().size() > 0) {
    market_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.market_);
  }
  if (from.has_spread()) {
    spread_ = new ::proto::SpreadProto(*from.spread_);
  } else {
    spread_ = NULL;
  }
  size_ = from.size_;
  // @@protoc_insertion_point(copy_constructor:proto.OrderBookProto)
}

void OrderBookProto::SharedCtor() {
  market_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&spread_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&size_) -
      reinterpret_cast<char*>(&spread_)) + sizeof(size_));
}

OrderBookProto::~OrderBookProto() {
  // @@protoc_insertion_point(destructor:proto.OrderBookProto)
  SharedDtor();
}

void OrderBookProto::SharedDtor() {
  market_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete spread_;
}

void OrderBookProto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* OrderBookProto::descriptor() {
  ::protobuf_orderbook_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_orderbook_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const OrderBookProto& OrderBookProto::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_orderbook_2eproto::scc_info_OrderBookProto.base);
  return *internal_default_instance();
}


void OrderBookProto::Clear() {
// @@protoc_insertion_point(message_clear_start:proto.OrderBookProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  points_.Clear();
  market_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && spread_ != NULL) {
    delete spread_;
  }
  spread_ = NULL;
  size_ = GOOGLE_ULONGLONG(0);
  _internal_metadata_.Clear();
}

bool OrderBookProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto.OrderBookProto)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string market = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_market()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->market().data(), static_cast<int>(this->market().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "proto.OrderBookProto.market"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint64 size = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &size_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .proto.SpreadProto spread = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_spread()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .proto.PricePointProto points = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_points()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto.OrderBookProto)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto.OrderBookProto)
  return false;
#undef DO_
}

void OrderBookProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto.OrderBookProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string market = 1;
  if (this->market().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->market().data(), static_cast<int>(this->market().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "proto.OrderBookProto.market");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->market(), output);
  }

  // uint64 size = 2;
  if (this->size() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->size(), output);
  }

  // .proto.SpreadProto spread = 3;
  if (this->has_spread()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->_internal_spread(), output);
  }

  // repeated .proto.PricePointProto points = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->points_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4,
      this->points(static_cast<int>(i)),
      output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:proto.OrderBookProto)
}

::google::protobuf::uint8* OrderBookProto::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:proto.OrderBookProto)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string market = 1;
  if (this->market().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->market().data(), static_cast<int>(this->market().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "proto.OrderBookProto.market");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->market(), target);
  }

  // uint64 size = 2;
  if (this->size() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->size(), target);
  }

  // .proto.SpreadProto spread = 3;
  if (this->has_spread()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->_internal_spread(), deterministic, target);
  }

  // repeated .proto.PricePointProto points = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->points_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        4, this->points(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto.OrderBookProto)
  return target;
}

size_t OrderBookProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto.OrderBookProto)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .proto.PricePointProto points = 4;
  {
    unsigned int count = static_cast<unsigned int>(this->points_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->points(static_cast<int>(i)));
    }
  }

  // string market = 1;
  if (this->market().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->market());
  }

  // .proto.SpreadProto spread = 3;
  if (this->has_spread()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *spread_);
  }

  // uint64 size = 2;
  if (this->size() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->size());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void OrderBookProto::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto.OrderBookProto)
  GOOGLE_DCHECK_NE(&from, this);
  const OrderBookProto* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const OrderBookProto>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto.OrderBookProto)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto.OrderBookProto)
    MergeFrom(*source);
  }
}

void OrderBookProto::MergeFrom(const OrderBookProto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto.OrderBookProto)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  points_.MergeFrom(from.points_);
  if (from.market().size() > 0) {

    market_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.market_);
  }
  if (from.has_spread()) {
    mutable_spread()->::proto::SpreadProto::MergeFrom(from.spread());
  }
  if (from.size() != 0) {
    set_size(from.size());
  }
}

void OrderBookProto::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto.OrderBookProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void OrderBookProto::CopyFrom(const OrderBookProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto.OrderBookProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool OrderBookProto::IsInitialized() const {
  return true;
}

void OrderBookProto::Swap(OrderBookProto* other) {
  if (other == this) return;
  InternalSwap(other);
}
void OrderBookProto::InternalSwap(OrderBookProto* other) {
  using std::swap;
  CastToBase(&points_)->InternalSwap(CastToBase(&other->points_));
  market_.Swap(&other->market_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(spread_, other->spread_);
  swap(size_, other->size_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata OrderBookProto::GetMetadata() const {
  protobuf_orderbook_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_orderbook_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::proto::OrderBookProto* Arena::CreateMaybeMessage< ::proto::OrderBookProto >(Arena* arena) {
  return Arena::CreateInternal< ::proto::OrderBookProto >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
