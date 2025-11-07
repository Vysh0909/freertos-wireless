#ifndef _LINUX_SYSFS_ATTRS_H
#define _LINUX_SYSFS_ATTRS_H

#include "device.h"  // include only if your project has it

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
    struct device_attribute dev_attr_index;       \
    struct device_attribute dev_attr_macaddress;  \
    struct device_attribute dev_attr_address_mask;\
    struct device_attribute dev_attr_addresses;   \
    struct device_attribute dev_attr_name;
#endif

/* Declare them globally */
DECLARE_SYSFS_ATTRS()

#endif /* _LINUX_SYSFS_ATTRS_H */

