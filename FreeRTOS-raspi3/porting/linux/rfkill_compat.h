#ifndef __RFKILL_COMPAT_H__
#define __RFKILL_COMPAT_H__

#include "types.h"
#include "slab.h"

#ifndef rfkill_pause_polling
#define rfkill_pause_polling(rfkill) ((void)0)
#endif

#ifndef ASSERT_RTNL
#define ASSERT_RTNL() ((void)0)
#endif

#ifndef rfkill_register
#define rfkill_register(rf)           (0)   /* return success */
#endif

#ifndef rfkill_destroy
#define rfkill_destroy(rf)            ((void)0)
#endif

#ifndef rfkill_resume_polling
#define rfkill_resume_polling(rf)     ((void)0)
#endif

#ifndef rfkill_unregister
#define rfkill_unregister(rf)   ((void)0)
#endif

#ifndef rcu_dereference_raw
#define rcu_dereference_raw(p) (p)
#endif

/*#ifndef kfree
#define kfree(ptr) ((void)0)
#endif
*/
#ifndef rfkill_set_hw_state_reason
#define rfkill_set_hw_state_reason(rfkill, blocked, reason) (0)  /* returns 0 for success */
#endif

#ifndef schedule_work
#define schedule_work(work) ((void)0)
#endif

/* Sysfs stub */
#ifndef sysfs_remove_link
#define sysfs_remove_link(kobj, name) ((void)0)
#endif

/* Network device stubs */
#ifndef unregister_netdevice
#define unregister_netdevice(netdev) ((void)0)
#endif

#ifndef synchronize_net
#define synchronize_net() ((void)0)
#endif

#ifndef rfkill_blocked
#define rfkill_blocked(rfkill) (0)
#endif

/* Ensure RFKILL_HARD_BLOCK_SIGNAL is defined */
#ifndef RFKILL_HARD_BLOCK_SIGNAL
enum rfkill_hard_block_reasons {
    RFKILL_HARD_BLOCK_DEFAULT = 0,
    RFKILL_HARD_BLOCK_SIGNAL  = 1,
    RFKILL_HARD_BLOCK_POWER   = 2,
};
#define RFKILL_HARD_BLOCK_SIGNAL  RFKILL_HARD_BLOCK_SIGNAL
#endif

struct rfkill_ops {
    int (*query)(void *data, int id);
    int (*set)(void *data, int id, bool blocked);
    void (*set_block)(void);
    void (*poll)(void *data);
};

#define RFKILL_TYPE_WLAN 0

static inline void *rfkill_alloc(const char *name, void *dev, int type,
                                 struct rfkill_ops *ops, void *data) {
    return NULL; // Dummy
}


#endif /* __RFKILL_COMPAT_H__ */

