/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: data.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "data.pb-c.h"
void   mpz_ser__init
                     (MpzSer         *message)
{
  static const MpzSer init_value = MPZ_SER__INIT;
  *message = init_value;
}
size_t mpz_ser__get_packed_size
                     (const MpzSer *message)
{
  assert(message->base.descriptor == &mpz_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mpz_ser__pack
                     (const MpzSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mpz_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mpz_ser__pack_to_buffer
                     (const MpzSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mpz_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MpzSer *
       mpz_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MpzSer *)
     protobuf_c_message_unpack (&mpz_ser__descriptor,
                                allocator, len, data);
}
void   mpz_ser__free_unpacked
                     (MpzSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mpz_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   mat_ser__init
                     (MatSer         *message)
{
  static const MatSer init_value = MAT_SER__INIT;
  *message = init_value;
}
size_t mat_ser__get_packed_size
                     (const MatSer *message)
{
  assert(message->base.descriptor == &mat_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t mat_ser__pack
                     (const MatSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &mat_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t mat_ser__pack_to_buffer
                     (const MatSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &mat_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MatSer *
       mat_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MatSer *)
     protobuf_c_message_unpack (&mat_ser__descriptor,
                                allocator, len, data);
}
void   mat_ser__free_unpacked
                     (MatSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &mat_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   octet_ser__init
                     (OctetSer         *message)
{
  static const OctetSer init_value = OCTET_SER__INIT;
  *message = init_value;
}
size_t octet_ser__get_packed_size
                     (const OctetSer *message)
{
  assert(message->base.descriptor == &octet_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t octet_ser__pack
                     (const OctetSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &octet_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t octet_ser__pack_to_buffer
                     (const OctetSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &octet_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
OctetSer *
       octet_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (OctetSer *)
     protobuf_c_message_unpack (&octet_ser__descriptor,
                                allocator, len, data);
}
void   octet_ser__free_unpacked
                     (OctetSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &octet_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   msp_ser__init
                     (MspSer         *message)
{
  static const MspSer init_value = MSP_SER__INIT;
  *message = init_value;
}
size_t msp_ser__get_packed_size
                     (const MspSer *message)
{
  assert(message->base.descriptor == &msp_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t msp_ser__pack
                     (const MspSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &msp_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t msp_ser__pack_to_buffer
                     (const MspSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &msp_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MspSer *
       msp_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MspSer *)
     protobuf_c_message_unpack (&msp_ser__descriptor,
                                allocator, len, data);
}
void   msp_ser__free_unpacked
                     (MspSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &msp_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor mpz_ser__field_descriptors[1] =
{
  {
    "val",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_INT64,
    offsetof(MpzSer, n_val),
    offsetof(MpzSer, val),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mpz_ser__field_indices_by_name[] = {
  0,   /* field[0] = val */
};
static const ProtobufCIntRange mpz_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor mpz_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mpz_ser",
  "MpzSer",
  "MpzSer",
  "",
  sizeof(MpzSer),
  1,
  mpz_ser__field_descriptors,
  mpz_ser__field_indices_by_name,
  1,  mpz_ser__number_ranges,
  (ProtobufCMessageInit) mpz_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor mat_ser__field_descriptors[3] =
{
  {
    "val",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(MatSer, n_val),
    offsetof(MatSer, val),
    &mpz_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "rows",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(MatSer, rows),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "cols",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(MatSer, cols),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned mat_ser__field_indices_by_name[] = {
  2,   /* field[2] = cols */
  1,   /* field[1] = rows */
  0,   /* field[0] = val */
};
static const ProtobufCIntRange mat_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor mat_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "mat_ser",
  "MatSer",
  "MatSer",
  "",
  sizeof(MatSer),
  3,
  mat_ser__field_descriptors,
  mat_ser__field_indices_by_name,
  1,  mat_ser__number_ranges,
  (ProtobufCMessageInit) mat_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor octet_ser__field_descriptors[3] =
{
  {
    "val",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_INT32,
    offsetof(OctetSer, n_val),
    offsetof(OctetSer, val),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "len",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(OctetSer, len),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "max",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(OctetSer, max),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned octet_ser__field_indices_by_name[] = {
  1,   /* field[1] = len */
  2,   /* field[2] = max */
  0,   /* field[0] = val */
};
static const ProtobufCIntRange octet_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor octet_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "octet_ser",
  "OctetSer",
  "OctetSer",
  "",
  sizeof(OctetSer),
  3,
  octet_ser__field_descriptors,
  octet_ser__field_indices_by_name,
  1,  octet_ser__number_ranges,
  (ProtobufCMessageInit) octet_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor msp_ser__field_descriptors[1] =
{
  {
    "mat",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(MspSer, mat),
    &mat_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned msp_ser__field_indices_by_name[] = {
  0,   /* field[0] = mat */
};
static const ProtobufCIntRange msp_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor msp_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "msp_ser",
  "MspSer",
  "MspSer",
  "",
  sizeof(MspSer),
  1,
  msp_ser__field_descriptors,
  msp_ser__field_indices_by_name,
  1,  msp_ser__number_ranges,
  (ProtobufCMessageInit) msp_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
