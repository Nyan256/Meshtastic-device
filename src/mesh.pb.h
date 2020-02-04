/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_MESH_PB_H_INCLUDED
#define PB_MESH_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _Data_Type {
    Data_Type_SIGNAL_OPAQUE = 0,
    Data_Type_CLEAR_TEXT = 1,
    Data_Type_CLEAR_READACK = 2
} Data_Type;

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(100) Data_payload_t;
typedef struct _Data {
    Data_Type typ;
    Data_payload_t payload;
} Data;

typedef struct _DenyNodeNum {
    pb_byte_t macaddr[6];
} DenyNodeNum;

typedef struct _MyNodeInfo {
    int32_t my_node_num;
} MyNodeInfo;

typedef struct _Position {
    double latitude;
    double longitude;
    int32_t altitude;
    int32_t battery_level;
    bool from_hardware;
} Position;

typedef struct _RadioConfig {
    uint32_t position_broadcast_msec;
    uint32_t min_broadcast_msec;
    int32_t tx_power;
    float center_freq;
    uint32_t bandwidth;
    int32_t spread_factor;
    int32_t coding_rate;
    bool keep_all_packets;
    bool promiscuous_mode;
} RadioConfig;

typedef struct _User {
    char id[16];
    char long_name[40];
    char short_name[5];
    pb_byte_t macaddr[6];
} User;

typedef struct _WantNodeNum {
    uint32_t desired_nodenum;
    pb_byte_t macaddr[6];
} WantNodeNum;

typedef struct _NodeInfo {
    int32_t num;
    bool has_user;
    User user;
    bool has_position;
    Position position;
    uint64_t last_seen;
    int32_t rx_power;
} NodeInfo;

typedef struct _SubPacket {
    pb_size_t which_variant;
    union {
        Position position;
        uint64_t time;
        Data data;
        User user;
        WantNodeNum want_node;
        DenyNodeNum deny_node;
    } variant;
} SubPacket;

typedef struct _MeshPacket {
    int32_t from;
    int32_t to;
    bool has_payload;
    SubPacket payload;
} MeshPacket;

typedef struct _DeviceState {
    bool has_radio;
    RadioConfig radio;
    pb_size_t node_db_count;
    NodeInfo node_db[32];
    pb_size_t receive_queue_count;
    MeshPacket receive_queue[32];
    int32_t my_node_num;
} DeviceState;

typedef struct _FromRadio {
    uint32_t num;
    pb_size_t which_variant;
    union {
        MeshPacket packet;
    } variant;
} FromRadio;

typedef struct _ToRadio {
    pb_size_t which_variant;
    union {
        MeshPacket packet;
    } variant;
} ToRadio;


/* Helper constants for enums */
#define _Data_Type_MIN Data_Type_SIGNAL_OPAQUE
#define _Data_Type_MAX Data_Type_CLEAR_READACK
#define _Data_Type_ARRAYSIZE ((Data_Type)(Data_Type_CLEAR_READACK+1))


/* Initializer values for message structs */
#define Position_init_default                    {0, 0, 0, 0, 0}
#define Data_init_default                        {_Data_Type_MIN, {0, {0}}}
#define User_init_default                        {"", "", "", {0}}
#define WantNodeNum_init_default                 {0, {0}}
#define DenyNodeNum_init_default                 {{0}}
#define SubPacket_init_default                   {0, {Position_init_default}}
#define MeshPacket_init_default                  {0, 0, false, SubPacket_init_default}
#define RadioConfig_init_default                 {0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_default                    {0, false, User_init_default, false, Position_init_default, 0, 0}
#define DeviceState_init_default                 {false, RadioConfig_init_default, 0, {NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default}, 0, {MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default}, 0}
#define MyNodeInfo_init_default                  {0}
#define FromRadio_init_default                   {0, 0, {MeshPacket_init_default}}
#define ToRadio_init_default                     {0, {MeshPacket_init_default}}
#define Position_init_zero                       {0, 0, 0, 0, 0}
#define Data_init_zero                           {_Data_Type_MIN, {0, {0}}}
#define User_init_zero                           {"", "", "", {0}}
#define WantNodeNum_init_zero                    {0, {0}}
#define DenyNodeNum_init_zero                    {{0}}
#define SubPacket_init_zero                      {0, {Position_init_zero}}
#define MeshPacket_init_zero                     {0, 0, false, SubPacket_init_zero}
#define RadioConfig_init_zero                    {0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_zero                       {0, false, User_init_zero, false, Position_init_zero, 0, 0}
#define DeviceState_init_zero                    {false, RadioConfig_init_zero, 0, {NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero}, 0, {MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero}, 0}
#define MyNodeInfo_init_zero                     {0}
#define FromRadio_init_zero                      {0, 0, {MeshPacket_init_zero}}
#define ToRadio_init_zero                        {0, {MeshPacket_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define Data_typ_tag                             1
#define Data_payload_tag                         2
#define DenyNodeNum_macaddr_tag                  1
#define MyNodeInfo_my_node_num_tag               1
#define Position_latitude_tag                    1
#define Position_longitude_tag                   2
#define Position_altitude_tag                    3
#define Position_battery_level_tag               4
#define Position_from_hardware_tag               5
#define RadioConfig_position_broadcast_msec_tag  1
#define RadioConfig_min_broadcast_msec_tag       2
#define RadioConfig_tx_power_tag                 3
#define RadioConfig_center_freq_tag              4
#define RadioConfig_bandwidth_tag                5
#define RadioConfig_spread_factor_tag            6
#define RadioConfig_coding_rate_tag              7
#define RadioConfig_keep_all_packets_tag         100
#define RadioConfig_promiscuous_mode_tag         101
#define User_id_tag                              1
#define User_long_name_tag                       2
#define User_short_name_tag                      3
#define User_macaddr_tag                         4
#define WantNodeNum_desired_nodenum_tag          1
#define WantNodeNum_macaddr_tag                  2
#define NodeInfo_num_tag                         1
#define NodeInfo_user_tag                        2
#define NodeInfo_position_tag                    3
#define NodeInfo_last_seen_tag                   4
#define NodeInfo_rx_power_tag                    5
#define SubPacket_position_tag                   1
#define SubPacket_time_tag                       2
#define SubPacket_data_tag                       3
#define SubPacket_user_tag                       4
#define SubPacket_want_node_tag                  5
#define SubPacket_deny_node_tag                  6
#define MeshPacket_from_tag                      1
#define MeshPacket_to_tag                        2
#define MeshPacket_payload_tag                   3
#define DeviceState_radio_tag                    1
#define DeviceState_node_db_tag                  2
#define DeviceState_receive_queue_tag            3
#define DeviceState_my_node_num_tag              4
#define FromRadio_packet_tag                     2
#define FromRadio_num_tag                        1
#define ToRadio_packet_tag                       1

/* Struct field encoding specification for nanopb */
#define Position_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, DOUBLE,   latitude,          1) \
X(a, STATIC,   SINGULAR, DOUBLE,   longitude,         2) \
X(a, STATIC,   SINGULAR, INT32,    altitude,          3) \
X(a, STATIC,   SINGULAR, INT32,    battery_level,     4) \
X(a, STATIC,   SINGULAR, BOOL,     from_hardware,     5)
#define Position_CALLBACK NULL
#define Position_DEFAULT NULL

#define Data_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    typ,               1) \
X(a, STATIC,   SINGULAR, BYTES,    payload,           2)
#define Data_CALLBACK NULL
#define Data_DEFAULT NULL

#define User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   id,                1) \
X(a, STATIC,   SINGULAR, STRING,   long_name,         2) \
X(a, STATIC,   SINGULAR, STRING,   short_name,        3) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           4)
#define User_CALLBACK NULL
#define User_DEFAULT NULL

#define WantNodeNum_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   desired_nodenum,   1) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           2)
#define WantNodeNum_CALLBACK NULL
#define WantNodeNum_DEFAULT NULL

#define DenyNodeNum_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           1)
#define DenyNodeNum_CALLBACK NULL
#define DenyNodeNum_DEFAULT NULL

#define SubPacket_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,position,variant.position),   1) \
X(a, STATIC,   ONEOF,    UINT64,   (variant,time,variant.time),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,data,variant.data),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,user,variant.user),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,want_node,variant.want_node),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,deny_node,variant.deny_node),   6)
#define SubPacket_CALLBACK NULL
#define SubPacket_DEFAULT NULL
#define SubPacket_variant_position_MSGTYPE Position
#define SubPacket_variant_data_MSGTYPE Data
#define SubPacket_variant_user_MSGTYPE User
#define SubPacket_variant_want_node_MSGTYPE WantNodeNum
#define SubPacket_variant_deny_node_MSGTYPE DenyNodeNum

#define MeshPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    from,              1) \
X(a, STATIC,   SINGULAR, INT32,    to,                2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  payload,           3)
#define MeshPacket_CALLBACK NULL
#define MeshPacket_DEFAULT NULL
#define MeshPacket_payload_MSGTYPE SubPacket

#define RadioConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   position_broadcast_msec,   1) \
X(a, STATIC,   SINGULAR, UINT32,   min_broadcast_msec,   2) \
X(a, STATIC,   SINGULAR, INT32,    tx_power,          3) \
X(a, STATIC,   SINGULAR, FLOAT,    center_freq,       4) \
X(a, STATIC,   SINGULAR, UINT32,   bandwidth,         5) \
X(a, STATIC,   SINGULAR, INT32,    spread_factor,     6) \
X(a, STATIC,   SINGULAR, INT32,    coding_rate,       7) \
X(a, STATIC,   SINGULAR, BOOL,     keep_all_packets, 100) \
X(a, STATIC,   SINGULAR, BOOL,     promiscuous_mode, 101)
#define RadioConfig_CALLBACK NULL
#define RadioConfig_DEFAULT NULL

#define NodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    num,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          3) \
X(a, STATIC,   SINGULAR, UINT64,   last_seen,         4) \
X(a, STATIC,   SINGULAR, INT32,    rx_power,          5)
#define NodeInfo_CALLBACK NULL
#define NodeInfo_DEFAULT NULL
#define NodeInfo_user_MSGTYPE User
#define NodeInfo_position_MSGTYPE Position

#define DeviceState_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  radio,             1) \
X(a, STATIC,   REPEATED, MESSAGE,  node_db,           2) \
X(a, STATIC,   REPEATED, MESSAGE,  receive_queue,     3) \
X(a, STATIC,   SINGULAR, INT32,    my_node_num,       4)
#define DeviceState_CALLBACK NULL
#define DeviceState_DEFAULT NULL
#define DeviceState_radio_MSGTYPE RadioConfig
#define DeviceState_node_db_MSGTYPE NodeInfo
#define DeviceState_receive_queue_MSGTYPE MeshPacket

#define MyNodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    my_node_num,       1)
#define MyNodeInfo_CALLBACK NULL
#define MyNodeInfo_DEFAULT NULL

#define FromRadio_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   2)
#define FromRadio_CALLBACK NULL
#define FromRadio_DEFAULT NULL
#define FromRadio_variant_packet_MSGTYPE MeshPacket

#define ToRadio_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   1)
#define ToRadio_CALLBACK NULL
#define ToRadio_DEFAULT NULL
#define ToRadio_variant_packet_MSGTYPE MeshPacket

extern const pb_msgdesc_t Position_msg;
extern const pb_msgdesc_t Data_msg;
extern const pb_msgdesc_t User_msg;
extern const pb_msgdesc_t WantNodeNum_msg;
extern const pb_msgdesc_t DenyNodeNum_msg;
extern const pb_msgdesc_t SubPacket_msg;
extern const pb_msgdesc_t MeshPacket_msg;
extern const pb_msgdesc_t RadioConfig_msg;
extern const pb_msgdesc_t NodeInfo_msg;
extern const pb_msgdesc_t DeviceState_msg;
extern const pb_msgdesc_t MyNodeInfo_msg;
extern const pb_msgdesc_t FromRadio_msg;
extern const pb_msgdesc_t ToRadio_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Position_fields &Position_msg
#define Data_fields &Data_msg
#define User_fields &User_msg
#define WantNodeNum_fields &WantNodeNum_msg
#define DenyNodeNum_fields &DenyNodeNum_msg
#define SubPacket_fields &SubPacket_msg
#define MeshPacket_fields &MeshPacket_msg
#define RadioConfig_fields &RadioConfig_msg
#define NodeInfo_fields &NodeInfo_msg
#define DeviceState_fields &DeviceState_msg
#define MyNodeInfo_fields &MyNodeInfo_msg
#define FromRadio_fields &FromRadio_msg
#define ToRadio_fields &ToRadio_msg

/* Maximum encoded size of messages (where known) */
#define Position_size                            42
#define Data_size                                104
#define User_size                                72
#define WantNodeNum_size                         14
#define DenyNodeNum_size                         8
#define SubPacket_size                           106
#define MeshPacket_size                          130
#define RadioConfig_size                         62
#define NodeInfo_size                            151
#define DeviceState_size                         9259
#define MyNodeInfo_size                          11
#define FromRadio_size                           139
#define ToRadio_size                             133

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
