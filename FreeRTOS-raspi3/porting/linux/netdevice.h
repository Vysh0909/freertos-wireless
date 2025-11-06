#ifndef __NETDEVICE_H__
#define __NETDEVICE_H__

/* Auto-generated stub header: netdevice.h */
struct kobject {
    // dummy placeholder to allow compilation
    char dummy;
};

struct device {
    struct kobject kobj;
};

struct net_device {
      unsigned char dev_addr[ETH_ALEN];
      bool netns_local;
      struct device dev;
};

#endif /* __NETDEVICE_H__ */
