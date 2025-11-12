#ifndef __NET_H__
#define __NET_H__

#ifndef netif_running
#define netif_running(dev) 1
#endif

#ifndef init_net
struct net { int dummy; };
extern struct net init_net;
#endif

#ifndef _LINUX_RCU_HEAD
struct rcu_head {
    void *next;
    void *func;
};
#endif

#ifndef _LINUX_MUTEX_H
struct mutex {
    int dummy;
};
#endif

#ifndef ETHTOOL_FWVERS_LEN
#define ETHTOOL_FWVERS_LEN 32
#endif

#ifndef NETDEV_ALIGN
#define NETDEV_ALIGN 32
#endif

#ifndef possible_net_t
typedef int possible_net_t;
#endif

struct device; 
static inline const char *dev_name(const struct device *dev)
{
	return 0;
}

#ifndef _LINUX_TIMER_LIST_H
struct timer_list { int dummy; };
#endif

#ifndef _LINUX_WORK_STRUCT_H
struct work_struct { 
	int dummy;
	void *data;  /* placeholder */
};

struct delayed_work {
    struct work_struct work;
    unsigned long delay;  /* placeholder for jiffies */
};
#endif

#ifndef spinlock_t
typedef int spinlock_t;
#endif

/* Dummy notifier_block for porting environment */
#ifndef NOTIFIER_BLOCK
#define NOTIFIER_BLOCK
struct notifier_block {
	 int (*notifier_call)(struct notifier_block *, unsigned long, void *);
         struct notifier_block *next;
          int priority;
};
#endif

/* Dummy pernet_operations for porting environment */
#ifndef PERNET_OPERATIONS
#define PERNET_OPERATIONS
struct pernet_operations {
     int (*init)(struct net *);
    void (*exit)(struct net *);
    int priority;
};
#endif

/* Dummy macros for __net_exit if used */
#ifndef __net_exit
#define __net_exit
#endif

#endif /* __NET_H__ */

