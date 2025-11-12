#ifndef _LINUX_SYSFS_ATTRS_H
#define _LINUX_SYSFS_ATTRS_H

#include "device.h"  // include only if your project has it
#include <stddef.h>
#include <stdint.h>

struct device;
struct device_attribute;

#ifndef sysfs_create_link
#define sysfs_create_link(kobj, kobj2, name) ((void *)(0))  /* return NULL */
#endif

/* Ensure ssize_t is defined */
#ifndef _SSIZE_T_DEFINED
typedef long ssize_t;
#define _SSIZE_T_DEFINED
#endif

struct attribute {
    const char *name;
    unsigned int mode;
};

/* Stub structures to satisfy sysfs references */
struct device_attribute {
    struct attribute attr;
    ssize_t (*show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*store)(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
};

#ifndef DECLARE_SYSFS_ATTRS
#define DECLARE_SYSFS_ATTRS()                     \
    extern struct device_attribute dev_attr_index;       \
    extern struct device_attribute dev_attr_macaddress;  \
    extern struct device_attribute dev_attr_address_mask;\
    extern struct device_attribute dev_attr_addresses;   \
    extern struct device_attribute dev_attr_name;
#endif

/* Declare them globally */
DECLARE_SYSFS_ATTRS()

#endif /* _LINUX_SYSFS_ATTRS_H */

