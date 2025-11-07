#ifndef __WORKQUEUE_H__
#define __WORKQUEUE_H__

#ifndef WQ_MEM_RECLAIM
#define WQ_MEM_RECLAIM 0x01  // dummy value for compatibility
#endif

#ifndef HAVE_REG_REGDB_WORK
extern struct work_struct reg_regdb_work;
#endif

/* Auto-generated stub header: workqueue.h */
static void *system_unbound_wq = NULL;

#endif /* __WORKQUEUE_H__ */
