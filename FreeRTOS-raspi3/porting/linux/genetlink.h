#ifndef __PORTING_GENETLINK_H
#define __PORTING_GENETLINK_H

#include <stdint.h>
#include "netlink.h"   /* Include nlattr definition */
#include "types.h"

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

/* Safe no-op versions of the macros */
#define NL_SET_ERR_MSG(_extack, _msg) \
    do { if (_extack) (_extack)->msg = _msg; } while (0)

#define NL_SET_ERR_MSG_ATTR(_extack, _attr, _msg) \
    do { if (_extack) (_extack)->msg = _msg; } while (0)

#endif /* __PORTING_GENETLINK_H */

