#ifndef __NETDEVICE_H__
#define __NETDEVICE_H__

/* Auto-generated stub header: netdevice.h */

#include "err.h"
#include "sysfs_attrs.h"
#include "class.h"
#include "sysfs_stubs.h"
#include "types.h"

#ifndef device_rename
static inline int device_rename(void *dev, const char *newname) {
    (void)dev;
    (void)newname;
    return 0;  /* indicate success */
}
#endif

#ifndef device_add
#define device_add(dev)               (0)   /* return success */
#endif

#ifndef device_del
#define device_del(dev)               ((void)0)
#endif

#ifndef debugfs_create_dir
#define debugfs_create_dir(name, parent) ((void *)0)
#endif

#ifndef debugfs_remove_recursive
#define debugfs_remove_recursive(dir) ((void)0)
#endif

#ifndef debugfs_change_name
#define debugfs_change_name(dir, fmt, ...) ((void)0)
#endif

#ifndef dev_change_net_namespace
#define dev_change_net_namespace(dev, net, fmt) (0)
#endif

#ifndef dev_close
#define dev_close(dev)                     ((void)0)
#endif

#ifndef put_device
#define put_device(dev) ((void)0)
#endif

#ifndef trace_cfg80211_stop_iface
#define trace_cfg80211_stop_iface(wiphy, wdev) ((void)0)
#endif

#ifndef register_netdevice
#define register_netdevice(dev) (0)  /* return 0 success */
#endif

#ifndef netdev_notifier_info_to_dev
#define netdev_notifier_info_to_dev(ptr) ((void *)0)
#endif

#ifndef SET_NETDEV_DEVTYPE
#define SET_NETDEV_DEVTYPE(dev, type) ((void)0)
#endif

#ifndef wake_up
#define wake_up(wait_queue) ((void)0)
#endif

#ifndef notifier_from_errno
#define notifier_from_errno(err) (0)
#endif

#ifndef net_eq
#define net_eq(a, b) (0)
#endif

#ifndef IFF_DONT_BRIDGE
#define IFF_DONT_BRIDGE 0x8000
#endif

/* Missing NETDEV notifier events */
#ifndef NETDEV_POST_INIT
#define NETDEV_POST_INIT        0
#define NETDEV_REGISTER         1
#define NETDEV_UNREGISTER       2
#define NETDEV_GOING_DOWN       3
#define NETDEV_DOWN             4
#define NETDEV_UP               5
#define NETDEV_PRE_UP           6
#endif

#ifndef IFF_ALLMULTI
#define IFF_ALLMULTI 0x200
#endif

/* Missing notifier return codes */
#ifndef NOTIFY_DONE
#define NOTIFY_DONE 0
#define NOTIFY_OK   1
#endif

#define ETH_ALEN    6   /* Octets in one ethernet addr */

struct kobject {
    // dummy placeholder to allow compilation
    char dummy;
};

struct device_driver {
    const char *name;
};

struct device {
	char name[32];
    struct device *parent;
    void *class;
    void *platform_data;
   struct kobject kobj;
   struct device_driver *driver;
};

struct net_device_ops;
struct net_device {
      unsigned char dev_addr[ETH_ALEN];
      bool netns_local;
      struct device dev;
      unsigned long priv_flags;      /* for priv_flags usage */
    struct wireless_dev *ieee80211_ptr; /* for ieee80211_ptr usage */
     int ifindex;          /* interface index */
    char name[16];
    unsigned int flags;
    unsigned char addr_len;
    struct {
        void *list;
    } mc;
    const struct net_device_ops *netdev_ops;
    unsigned int features;
    unsigned int hw_features;
    unsigned int min_mtu;
    unsigned int max_mtu;
    unsigned int needed_headroom;
    unsigned int needed_tailroom;
    unsigned char perm_addr[6];
    bool needs_free_netdev;
    unsigned int pcpu_stat_type;

    unsigned short type;

};
struct net_device_ops {
    int (*ndo_open)(struct net_device *dev);
    int (*ndo_stop)(struct net_device *dev);
    void (*ndo_uninit)(struct net_device *dev);
    int (*ndo_start_xmit)(void *skb, struct net_device *dev);
    void (*ndo_set_rx_mode)(struct net_device *dev);
    int (*ndo_set_mac_address)(struct net_device *dev, void *addr);
    int (*ndo_setup_tc)(struct net_device *dev, int type, void *type_data);
    int (*ndo_fill_forward_path)(struct net_device *dev, void *path, void *dst);
    int (*ndo_select_queue)(struct net_device *dev, void *skb, void *accel_priv, void *select_queue_fallback);
};

struct net_device_path_ctx {
    struct net_device *dev;   /* device pointer */
    unsigned char daddr[6];   /* destination MAC address */
};

struct net_device_path {
    struct net_device *dev;
    int type;
};


#endif /* __NETDEVICE_H__ */
