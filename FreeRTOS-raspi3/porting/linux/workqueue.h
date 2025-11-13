#ifndef __WORKQUEUE_H__
#define __WORKQUEUE_H__

#include <stddef.h>
#include "net.h"

#ifndef alloc_ordered_workqueue
#define alloc_ordered_workqueue(name, flags, ...)   ((void *)0)
#endif

#ifndef destroy_workqueue
#define destroy_workqueue(wq)     ((void)0)
#endif

#ifndef register_pernet_device
#define register_pernet_device(ops)   (0)
#endif

#ifndef unregister_pernet_device
#define unregister_pernet_device(ops) ((void)0)
#endif

#ifndef register_netdevice_notifier
#define register_netdevice_notifier(notifier)  (0)
#endif

#ifndef unregister_netdevice_notifier
#define unregister_netdevice_notifier(notifier) ((void)0)
#endif

#ifndef WQ_MEM_RECLAIM
#define WQ_MEM_RECLAIM 0x01  // dummy value for compatibility
#endif

#ifndef HAVE_REG_REGDB_WORK
extern struct work_struct reg_regdb_work;
#endif

/* Auto-generated stub header: workqueue.h */
//static void *system_unbound_wq = NULL;
static void *system_unbound_wq __attribute__((unused)) = NULL;
struct workqueue_struct {
    int dummy;
};

extern struct workqueue_struct *system_power_efficient_wq;
extern struct work_struct reg_work;

static void reg_check_chans(struct work_struct *work) __attribute__((unused));
static void reg_check_chans(struct work_struct *work)
{
    
}

typedef int spinlock_t;
//static spinlock_t reg_requests_lock;
static spinlock_t reg_requests_lock __attribute__((unused));
extern spinlock_t reg_pending_beacons_lock;
extern spinlock_t reg_indoor_lock;

static inline void spin_lock(spinlock_t *lock)   { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }

#endif /* __WORKQUEUE_H__ */
