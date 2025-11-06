#ifndef __LINUX_RCUPDATE_H_
#define __LINUX_RCUPDATE_H_

typedef struct {
    int dummy;
} rcu_head;

#define kfree_rcu(ptr, rcu_head) free(ptr)
#define RCU_INIT_POINTER(p, val) ((p) = (val))

#endif /* __LINUX_RCUPDATE_H_ */
