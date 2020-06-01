/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: fame.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "fame.pb-c.h"
void   cfe_fame_pub_key_ser__init
                     (CfeFamePubKeySer         *message)
{
  static const CfeFamePubKeySer init_value = CFE_FAME_PUB_KEY_SER__INIT;
  *message = init_value;
}
size_t cfe_fame_pub_key_ser__get_packed_size
                     (const CfeFamePubKeySer *message)
{
  assert(message->base.descriptor == &cfe_fame_pub_key_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cfe_fame_pub_key_ser__pack
                     (const CfeFamePubKeySer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cfe_fame_pub_key_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cfe_fame_pub_key_ser__pack_to_buffer
                     (const CfeFamePubKeySer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cfe_fame_pub_key_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CfeFamePubKeySer *
       cfe_fame_pub_key_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CfeFamePubKeySer *)
     protobuf_c_message_unpack (&cfe_fame_pub_key_ser__descriptor,
                                allocator, len, data);
}
void   cfe_fame_pub_key_ser__free_unpacked
                     (CfeFamePubKeySer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cfe_fame_pub_key_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   cfe_fame_sec_key_ser__init
                     (CfeFameSecKeySer         *message)
{
  static const CfeFameSecKeySer init_value = CFE_FAME_SEC_KEY_SER__INIT;
  *message = init_value;
}
size_t cfe_fame_sec_key_ser__get_packed_size
                     (const CfeFameSecKeySer *message)
{
  assert(message->base.descriptor == &cfe_fame_sec_key_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cfe_fame_sec_key_ser__pack
                     (const CfeFameSecKeySer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cfe_fame_sec_key_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cfe_fame_sec_key_ser__pack_to_buffer
                     (const CfeFameSecKeySer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cfe_fame_sec_key_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CfeFameSecKeySer *
       cfe_fame_sec_key_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CfeFameSecKeySer *)
     protobuf_c_message_unpack (&cfe_fame_sec_key_ser__descriptor,
                                allocator, len, data);
}
void   cfe_fame_sec_key_ser__free_unpacked
                     (CfeFameSecKeySer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cfe_fame_sec_key_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   cfe_fame_attrib_keys_ser__init
                     (CfeFameAttribKeysSer         *message)
{
  static const CfeFameAttribKeysSer init_value = CFE_FAME_ATTRIB_KEYS_SER__INIT;
  *message = init_value;
}
size_t cfe_fame_attrib_keys_ser__get_packed_size
                     (const CfeFameAttribKeysSer *message)
{
  assert(message->base.descriptor == &cfe_fame_attrib_keys_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cfe_fame_attrib_keys_ser__pack
                     (const CfeFameAttribKeysSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cfe_fame_attrib_keys_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cfe_fame_attrib_keys_ser__pack_to_buffer
                     (const CfeFameAttribKeysSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cfe_fame_attrib_keys_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CfeFameAttribKeysSer *
       cfe_fame_attrib_keys_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CfeFameAttribKeysSer *)
     protobuf_c_message_unpack (&cfe_fame_attrib_keys_ser__descriptor,
                                allocator, len, data);
}
void   cfe_fame_attrib_keys_ser__free_unpacked
                     (CfeFameAttribKeysSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cfe_fame_attrib_keys_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   cfe_fame_cipher_ser__init
                     (CfeFameCipherSer         *message)
{
  static const CfeFameCipherSer init_value = CFE_FAME_CIPHER_SER__INIT;
  *message = init_value;
}
size_t cfe_fame_cipher_ser__get_packed_size
                     (const CfeFameCipherSer *message)
{
  assert(message->base.descriptor == &cfe_fame_cipher_ser__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cfe_fame_cipher_ser__pack
                     (const CfeFameCipherSer *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cfe_fame_cipher_ser__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cfe_fame_cipher_ser__pack_to_buffer
                     (const CfeFameCipherSer *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cfe_fame_cipher_ser__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
CfeFameCipherSer *
       cfe_fame_cipher_ser__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CfeFameCipherSer *)
     protobuf_c_message_unpack (&cfe_fame_cipher_ser__descriptor,
                                allocator, len, data);
}
void   cfe_fame_cipher_ser__free_unpacked
                     (CfeFameCipherSer *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &cfe_fame_cipher_ser__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor cfe_fame_pub_key_ser__field_descriptors[4] =
{
  {
    "part_G2_1",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFamePubKeySer, part_g2_1),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "part_G2_2",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFamePubKeySer, part_g2_2),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "part_GT_1",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFamePubKeySer, part_gt_1),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "part_GT_2",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFamePubKeySer, part_gt_2),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cfe_fame_pub_key_ser__field_indices_by_name[] = {
  0,   /* field[0] = part_G2_1 */
  1,   /* field[1] = part_G2_2 */
  2,   /* field[2] = part_GT_1 */
  3,   /* field[3] = part_GT_2 */
};
static const ProtobufCIntRange cfe_fame_pub_key_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor cfe_fame_pub_key_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cfe_fame_pub_key_ser",
  "CfeFamePubKeySer",
  "CfeFamePubKeySer",
  "",
  sizeof(CfeFamePubKeySer),
  4,
  cfe_fame_pub_key_ser__field_descriptors,
  cfe_fame_pub_key_ser__field_indices_by_name,
  1,  cfe_fame_pub_key_ser__number_ranges,
  (ProtobufCMessageInit) cfe_fame_pub_key_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor cfe_fame_sec_key_ser__field_descriptors[2] =
{
  {
    "part_int",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameSecKeySer, n_part_int),
    offsetof(CfeFameSecKeySer, part_int),
    &mpz_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "part_G1",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameSecKeySer, n_part_g1),
    offsetof(CfeFameSecKeySer, part_g1),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cfe_fame_sec_key_ser__field_indices_by_name[] = {
  1,   /* field[1] = part_G1 */
  0,   /* field[0] = part_int */
};
static const ProtobufCIntRange cfe_fame_sec_key_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor cfe_fame_sec_key_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cfe_fame_sec_key_ser",
  "CfeFameSecKeySer",
  "CfeFameSecKeySer",
  "",
  sizeof(CfeFameSecKeySer),
  2,
  cfe_fame_sec_key_ser__field_descriptors,
  cfe_fame_sec_key_ser__field_indices_by_name,
  1,  cfe_fame_sec_key_ser__number_ranges,
  (ProtobufCMessageInit) cfe_fame_sec_key_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor cfe_fame_attrib_keys_ser__field_descriptors[4] =
{
  {
    "k0",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameAttribKeysSer, n_k0),
    offsetof(CfeFameAttribKeysSer, k0),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "k",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameAttribKeysSer, n_k),
    offsetof(CfeFameAttribKeysSer, k),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "k_prime",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameAttribKeysSer, n_k_prime),
    offsetof(CfeFameAttribKeysSer, k_prime),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "row_to_attrib",
    4,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_INT64,
    offsetof(CfeFameAttribKeysSer, n_row_to_attrib),
    offsetof(CfeFameAttribKeysSer, row_to_attrib),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cfe_fame_attrib_keys_ser__field_indices_by_name[] = {
  1,   /* field[1] = k */
  0,   /* field[0] = k0 */
  2,   /* field[2] = k_prime */
  3,   /* field[3] = row_to_attrib */
};
static const ProtobufCIntRange cfe_fame_attrib_keys_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor cfe_fame_attrib_keys_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cfe_fame_attrib_keys_ser",
  "CfeFameAttribKeysSer",
  "CfeFameAttribKeysSer",
  "",
  sizeof(CfeFameAttribKeysSer),
  4,
  cfe_fame_attrib_keys_ser__field_descriptors,
  cfe_fame_attrib_keys_ser__field_indices_by_name,
  1,  cfe_fame_attrib_keys_ser__number_ranges,
  (ProtobufCMessageInit) cfe_fame_attrib_keys_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor cfe_fame_cipher_ser__field_descriptors[4] =
{
  {
    "ct0",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameCipherSer, n_ct0),
    offsetof(CfeFameCipherSer, ct0),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ct",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(CfeFameCipherSer, n_ct),
    offsetof(CfeFameCipherSer, ct),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ct_prime",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFameCipherSer, ct_prime),
    &octet_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "msp",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(CfeFameCipherSer, msp),
    &msp_ser__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cfe_fame_cipher_ser__field_indices_by_name[] = {
  1,   /* field[1] = ct */
  0,   /* field[0] = ct0 */
  2,   /* field[2] = ct_prime */
  3,   /* field[3] = msp */
};
static const ProtobufCIntRange cfe_fame_cipher_ser__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor cfe_fame_cipher_ser__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cfe_fame_cipher_ser",
  "CfeFameCipherSer",
  "CfeFameCipherSer",
  "",
  sizeof(CfeFameCipherSer),
  4,
  cfe_fame_cipher_ser__field_descriptors,
  cfe_fame_cipher_ser__field_indices_by_name,
  1,  cfe_fame_cipher_ser__number_ranges,
  (ProtobufCMessageInit) cfe_fame_cipher_ser__init,
  NULL,NULL,NULL    /* reserved[123] */
};
