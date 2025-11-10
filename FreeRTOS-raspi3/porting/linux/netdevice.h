#ifndef __NETDEVICE_H__
#define __NETDEVICE_H__

/* Auto-generated stub header: netdevice.h */

#include "err.h"
#include "sysfs_attrs.h"
#include "class.h"
#include "sysfs_stubs.h"
#include "types.h"

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

struct net_device {
      unsigned char dev_addr[ETH_ALEN];
      bool netns_local;
      struct device dev;
      unsigned long priv_flags;      /* for priv_flags usage */
    struct wireless_dev *ieee80211_ptr; /* for ieee80211_ptr usage */
};


#endif /* __NETDEVICE_H__ */
