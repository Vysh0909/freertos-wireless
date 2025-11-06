#ifndef __NETDEVICE_H__
#define __NETDEVICE_H__

/* Auto-generated stub header: netdevice.h */

#ifndef IFF_DONT_BRIDGE
#define IFF_DONT_BRIDGE 0x8000
#endif

struct kobject {
    // dummy placeholder to allow compilation
    char dummy;
};

struct device {
	char name[32];
    struct device *parent;
    void *class;
    void *platform_data;
   struct kobject kobj;
};

struct net_device {
      unsigned char dev_addr[ETH_ALEN];
      bool netns_local;
      struct device dev;
      unsigned long priv_flags;      /* for priv_flags usage */
    struct wireless_dev *ieee80211_ptr; /* for ieee80211_ptr usage */
};


#endif /* __NETDEVICE_H__ */
