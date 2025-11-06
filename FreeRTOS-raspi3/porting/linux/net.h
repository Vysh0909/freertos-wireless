#ifndef __NET_H__
#define __NET_H__


#ifndef _LINUX_LIST_H
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};
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

#ifndef _LINUX_DEVICE_H
struct device {
    char name[32];
    struct device *parent;
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

#ifndef _LINUX_REGULATORY_REQUEST_H
struct regulatory_request {
    int dummy;
};
#endif

#ifndef dev_name
static inline const char *dev_name(const struct device *dev)
{
    return dev ? dev->name : "unknown";
}
#endif

#ifndef _LINUX_TIMER_LIST_H
struct timer_list { int dummy; };
#endif

#ifndef _LINUX_WORK_STRUCT_H
struct work_struct { int dummy; };
#endif

#ifndef spinlock_t
typedef int spinlock_t;
#endif


#endif /* __NET_H__ */

