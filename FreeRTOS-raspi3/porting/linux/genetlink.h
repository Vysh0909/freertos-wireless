#ifndef __PORTING_GENETLINK_H
#define __PORTING_GENETLINK_H

#include <stdint.h>

struct netlink_ext_ack {
    const char *msg;
};

struct genl_info {
    void *userhdr;
    void *user_ptr[2];
    void *attrs;              /* attribute array */
    struct netlink_ext_ack *extack;
};

#define NL_SET_ERR_MSG(_extack, _msg) \
    do { (void)(_extack); (void)(_msg); } while (0)

#define NL_SET_ERR_MSG_ATTR(_extack, _attr, _msg) \
    do { (void)(_extack); (void)(_attr); (void)(_msg); } while (0)

#endif /* __PORTING_GENETLINK_H */

