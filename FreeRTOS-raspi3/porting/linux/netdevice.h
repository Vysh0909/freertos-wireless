#ifndef __NETDEVICE_H__
#define __NETDEVICE_H__

/* Auto-generated stub header: netdevice.h */

#include "err.h"
#include "sysfs_attrs.h"
#include "class.h"
#include "sysfs_stubs.h"
#include "types.h"
#include "drop_reason.h"

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

#ifndef NETIF_F_RXCSUM
#define NETIF_F_RXCSUM  0x00000020
#endif

#ifndef NET_NAME_ENUM
#define NET_NAME_ENUM 0
#endif

#ifndef ETH_P_802_3_MIN
#define ETH_P_802_3_MIN 0x0600  /* Minimum valid Ethernet type */
#endif

/* ---- BITS ---- */
#ifndef BITS_PER_BYTE
#define BITS_PER_BYTE 8
#endif

/* Simple bitmap implementation for 256 bits */
#ifndef DECLARE_BITMAP
#define DECLARE_BITMAP(name, bits) \
    unsigned long name[((bits) + (sizeof(unsigned long)*8 - 1)) / (sizeof(unsigned long)*8)]
#endif

#ifndef CONFIG_MAC80211_RC_DEFAULT
#define CONFIG_MAC80211_RC_DEFAULT "minstrel_ht"
#endif

/* ---- SKB flags and checksum ---- */
#ifndef CHECKSUM_PARTIAL
#define CHECKSUM_PARTIAL 1
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
#define IFF_TX_SKB_SHARING      0x10000
#define IFF_NO_QUEUE            0x20000
#define IFF_LIVE_ADDR_CHANGE    0x40000
#define ARPHRD_IEEE80211_RADIOTAP 803  /* from linux/if_arp.h */
#define NETDEV_PCPU_STAT_TSTATS  1

#define ETH_HLEN   14  /* Ethernet header length */

#define NETIF_F_IP_CSUM          (1 << 0)
#define NETIF_F_IPV6_CSUM        (1 << 1)
#define NETIF_F_HW_CSUM          (1 << 2)
#define NETIF_F_SG               (1 << 3)
#define NETIF_F_HIGHDMA          (1 << 4)
#define NETIF_F_GSO_SOFTWARE     (1 << 5)
#define NETIF_F_HW_TC            (1 << 6)

#define NETDEV_CHANGENAME        0x0019

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
