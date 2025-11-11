#ifndef __PORTING_GENETLINK_H
#define __PORTING_GENETLINK_H

#include <stdint.h>
#include "netlink.h"   /* Include nlattr definition */
#include "types.h"
#ifndef U8_MAX
#define U8_MAX 255
#endif

#ifndef U16_MAX
#define U16_MAX 65535
#endif

#ifndef U32_MAX
#define U32_MAX 0xFFFFFFFF
#endif

#ifndef U64_MAX
#define U64_MAX 0xFFFFFFFFFFFFFFFFULL
#endif

struct nla_policy {
    u16 type;
    u16 len;   /* optional: used for binary or max value validation */
};

enum nla_type {
    NLA_UNSPEC = 0,
    NLA_U8,
    NLA_U16,
    NLA_U32,
    NLA_U64,
    NLA_S8,
    NLA_S16,
    NLA_S32,
    NLA_FLAG,
    NLA_BINARY,
    NLA_REJECT
};

#define NLA_POLICY_MIN(type_enum, minval)    ((struct nla_policy){ .type = type_enum, .len = minval })
#define NLA_POLICY_MAX(type_enum, maxval)    ((struct nla_policy){ .type = type_enum, .len = maxval })
#define NLA_POLICY_RANGE(type_enum, minval, maxval) ((struct nla_policy){ .type = type_enum, .len = maxval })
#define NLA_POLICY_EXACT_LEN(lenval)            ((struct nla_policy){ .len = lenval })
#define NLA_POLICY_EXACT_LEN_WARN(lenval)       ((struct nla_policy){ .len = lenval })
#define NLA_POLICY_NESTED(array)                ((struct nla_policy){ .type = NLA_BINARY })
#define NLA_POLICY_NESTED_ARRAY(array)          ((struct nla_policy){ .type = NLA_BINARY })
#define NLA_POLICY_ETH_ADDR                      ((struct nla_policy){ .len = 6 })

struct netlink_range_validation {
    u32 min;
    u32 max;
};

struct netlink_ext_ack {
    const char *msg;
};

struct genl_info {
    void *userhdr;
    void *user_ptr[2];
    struct nlattr **attrs;          /* FIXED: was void*, now array of nlattr pointers */
    struct netlink_ext_ack *extack;
    u32 snd_portid;
};
struct genl_multicast_group {
    const char *name;
    int id;
};

/* Safe no-op versions of the macros */
#define NL_SET_ERR_MSG(_extack, _msg) \
    do { if (_extack) (_extack)->msg = _msg; } while (0)

#define NL_SET_ERR_MSG_ATTR(_extack, _attr, _msg) \
    do { if (_extack) (_extack)->msg = _msg; } while (0)

#endif /* __PORTING_GENETLINK_H */

