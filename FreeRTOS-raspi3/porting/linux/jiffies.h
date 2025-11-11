#ifndef __LINUX_JIFFIES_H_
#define __LINUX_JIFFIES_H_

#ifndef atomic_inc
#define atomic_inc(v) (*(v))++
#endif

#ifndef atomic_dec_return
#define atomic_dec_return(v) (--(*(v)))
#endif

#ifndef lockdep_assert_held
#define lockdep_assert_held(lock) ((void)0)
#endif

#ifndef jiffies_to_msecs
#define jiffies_to_msecs(j) (j)  // adjust conversion if needed
#endif

extern unsigned long jiffies;

#endif /* __LINUX_JIFFIES_H_ */
