#ifndef _SYSFS_STUBS_H
#define _SYSFS_STUBS_H

#include <stddef.h>  /* For NULL */
#include <stdint.h>  /* For standard integer types */

/* Define ssize_t if missing */
#ifndef _SSIZE_T_DEFINED
typedef long ssize_t;
#define _SSIZE_T_DEFINED
#endif

/* Stub for ieee80211 sysfs attribute groups */
static const void *ieee80211_groups[] = { NULL };

/* Stub for net namespace type operations */
struct kobj_ns_type_operations {
    const char *name;
};
static const struct kobj_ns_type_operations net_ns_type_operations = {
    .name = "net_ns_stub",
};

#endif /* _SYSFS_STUBS_H */

