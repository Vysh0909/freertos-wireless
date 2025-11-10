#ifndef __WORKQUEUE_H__
#define __WORKQUEUE_H__

#include <stddef.h>
#include "net.h"

#ifndef WQ_MEM_RECLAIM
#define WQ_MEM_RECLAIM 0x01  // dummy value for compatibility
#endif

#ifndef HAVE_REG_REGDB_WORK
extern struct work_struct reg_regdb_work;
#endif

/* Auto-generated stub header: workqueue.h */
static void *system_unbound_wq = NULL;

struct workqueue_struct {
    int dummy;
};

struct workqueue_struct system_power_efficient_wq;
struct work_struct reg_work;

static void reg_check_chans(struct work_struct *work)
{
    (void)work;
}

typedef int spinlock_t;
static spinlock_t reg_requests_lock;
extern spinlock_t reg_pending_beacons_lock;
extern spinlock_t reg_indoor_lock;

static inline void spin_lock(spinlock_t *lock)   { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }

#endif /* __WORKQUEUE_H__ */
