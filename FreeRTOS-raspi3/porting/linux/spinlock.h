#ifndef __LINUX_SPINLOCK_H_
#define __LINUX_SPINLOCK_H_

#ifndef spin_lock_irq
#define spin_lock_irq(lock)       ((void)0)
#endif

#ifndef spin_unlock_irq
#define spin_unlock_irq(lock)     ((void)0)
#endif

#ifndef spin_lock_init
#define spin_lock_init(lock)      ((void)0)
#endif

#ifndef mutex_init
#define mutex_init(mtx)           ((void)0)
#endif

#ifndef queue_work
#define queue_work(wq, work)      ((void)0)
#endif

#ifndef atomic_inc_return
#define atomic_inc_return(v)      (++(*(v)))  /* simple non-atomic increment */
#endif

#ifndef atomic_dec
#define atomic_dec(v)             ((*(v))--)  /* simple non-atomic decrement */
#endif

#ifndef dev_set_name
static inline int dev_set_name(void *dev, const char *fmt, ...) {
    (void)dev;
    (void)fmt;
    return 0;  /* indicate success */
}
#endif

#ifndef INIT_DELAYED_WORK
#define INIT_DELAYED_WORK(work, fn) ((void)0)
#endif

#ifndef INIT_WORK
#define INIT_WORK(work, fn)       ((void)0)
#endif

#ifndef device_initialize
#define device_initialize(dev)    ((void)0)
#endif

#ifndef device_enable_async_suspend
#define device_enable_async_suspend(dev) ((void)0)
#endif

#endif /* __LINUX_SPINLOCK_H_ */
