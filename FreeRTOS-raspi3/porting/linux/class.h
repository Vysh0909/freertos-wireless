#ifndef _LINUX_CLASS_H
#define _LINUX_CLASS_H

/* Minimal struct class definition to satisfy sysfs.c */
struct class {
    const char *name;
    void (*dev_release)(void *dev);
    void *dev_groups;
    void *pm;
    void *ns_type;
    const void *namespace;
};

#endif /* _LINUX_CLASS_H */

