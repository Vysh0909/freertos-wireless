#ifndef _LINUX_NETLINK_H
#define _LINUX_NETLINK_H

#include <stddef.h>
#include <stdint.h>

struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

#define nla_data(nla) ((void *)((char *)(nla) + sizeof(struct nlattr)))
#define nla_len(nla)  ((int)((nla)->nla_len - sizeof(struct nlattr)))
#define nla_ok(nla, rem) ((rem) > 0)
#define nla_next(nla, rem) ((struct nlattr *)((char *)(nla) + (nla)->nla_len))
#define nla_get_u32(nla) (*(uint32_t *)nla_data(nla))

/* iteration helper */
#define nla_for_each_nested(pos, nla, rem) \
    for (rem = nla_len(nla), pos = (struct nlattr *)nla_data(nla); \
         nla_ok(pos, rem); \
         pos = nla_next(pos, rem))

#endif /* _LINUX_NETLINK_H */

