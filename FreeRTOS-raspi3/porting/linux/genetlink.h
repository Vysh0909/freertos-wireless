#ifndef __PORTING_GENETLINK_H
#define __PORTING_GENETLINK_H

#include <stdint.h>
#include "netlink.h"   /* Include nlattr definition */
#include "types.h"
#include "skbuff.h"

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

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

#ifndef GENL_HDRLEN
#define GENL_HDRLEN 4   // typical netlink family header size in Linux
#endif

#ifndef NLA_F_NESTED
#define NLA_F_NESTED NLA_NESTED
#endif

#ifndef NETLINK_CB
#define NETLINK_CB(skb) (*(skb))   /* Returns skb itself as a placeholder */
#endif

#ifndef NLM_F_MULTI
#define NLM_F_MULTI 0x02
#endif

#ifndef NET_NAME_USER
#define NET_NAME_USER 1
#endif

#ifndef NLA_HDRLEN
#define NLA_HDRLEN 4
#endif

#ifndef NLMSG_GOODSIZE
#define NLMSG_GOODSIZE 4096
#endif

#ifndef GENL_DONT_VALIDATE_STRICT
#define GENL_DONT_VALIDATE_STRICT 0x01
#endif

#ifndef GENL_DONT_VALIDATE_DUMP
#define GENL_DONT_VALIDATE_DUMP 0x02
#endif

#ifndef GENL_UNS_ADMIN_PERM
#define GENL_UNS_ADMIN_PERM 0x04
#endif

#ifndef GENL_ADMIN_PERM
#define GENL_ADMIN_PERM 0x08
#endif

#ifndef NETLINK_URELEASE
#define NETLINK_URELEASE 0x10
#endif

#ifndef NETLINK_GENERIC
#define NETLINK_GENERIC 16
#endif

#ifndef S32_MIN
#define S32_MIN    (-2147483647 - 1)
#endif

#ifndef S32_MAX
#define S32_MAX    (2147483647)
#endif

#ifndef __ro_after_init
#define __ro_after_init  /* no-op for user-space/porting */
#endif

#define GENL_DONT_VALIDATE_STRICT 0x01
#define GENL_DONT_VALIDATE_DUMP   0x02

#ifndef THIS_MODULE
#define THIS_MODULE ((void *)0)
#endif

struct genl_info;
struct sk_buff;
struct netlink_callback;

struct genl_ops {
    int cmd;
    int flags;
    int (*doit)(void *info);
    int (*dumpit)(void *cb);
    int validate;
    int (*done)(struct netlink_callback *cb);
    unsigned int internal_flags;
};

struct genl_split_ops {
    unsigned int cmd;
    unsigned int internal_flags;
    unsigned int maxattr;
    unsigned int policy;
};

/* Stub definition for genl_small_ops */
struct genl_small_ops {
    int cmd;
    int (*doit)(struct sk_buff *skb, struct genl_info *info);
    unsigned int internal_flags;
    unsigned int flags;
    int (*dumpit)(struct sk_buff *skb, struct netlink_callback *cb);
    unsigned int validate;
};

/*struct genl_small_ops {
    int cmd;
    int flags;
    int (*doit)(void *info);
};
*/
struct nlmsghdr {
    int nlmsg_seq;
    __u32 nlmsg_len;
    __u16 nlmsg_type;
    __u16 nlmsg_flags;
    __u32 nlmsg_pid;
};

struct netlink_callback {
    long args[6];       /* placeholder for callback arguments */
    //void *nlh;        
    struct sk_buff *skb;/* optional: can be NULL */
     int min_dump_alloc;
     struct nlmsghdr *nlh;
     unsigned int seq;
     void *extack;
};

struct netlink_notify {
    int protocol;
};

struct genl_family {
    int hdrsize;        /* header size (GENL_HDRLEN + hdrsize) */
    int maxattr;        /* maximum attribute index */
    const char *name;
    unsigned int id;
    unsigned int version;
    /* new fields in recent kernels */
    const struct genl_ops *ops;
    unsigned int n_ops;

    const struct genl_small_ops *small_ops;
    unsigned int n_small_ops;

    const void *mcgrps;
    unsigned int n_mcgrps;

    unsigned int resv_start_op;
    bool parallel_ops;

    const void *policy;   /* originally: const struct nla_policy * */
    bool netnsok;
    int (*pre_doit)(const void *ops, struct sk_buff *skb, struct genl_info *info);
    void (*post_doit)(const void *ops, struct sk_buff *skb, struct genl_info *info);
    void *module;


};


struct nla_policy {
    u16 type;
    u16 len;   /* optional: used for binary or max value validation */
    u16 strict_start_type;
     void *validate_fn;
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

/* Attribute types */
#define NLA_NUL_STRING NLA_BINARY
#define NLA_NESTED     NLA_BINARY

/* Validation macros */
#define NLA_POLICY_VALIDATE_FN(type_enum, fn, ...) ((struct nla_policy){ .type = type_enum, .validate_fn = (void *)fn })
#define NLA_POLICY_ETH_ADDR_COMPAT NLA_POLICY_ETH_ADDR

/* Length macros for FreeRTOS */
#define NLA_POLICY_MIN_LEN(lenval)  ((struct nla_policy){ .type = NLA_BINARY, .len = lenval })
#define NLA_POLICY_FULL_RANGE(type_enum, range_ptr) ((struct nla_policy){ .type = type_enum, .len = 0xFFFFFFFF })

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
     u32 snd_seq;
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

