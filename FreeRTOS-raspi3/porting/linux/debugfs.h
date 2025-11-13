#ifndef __LINUX_DEBUGFS_H_
#define __LINUX_DEBUGFS_H_

#include "fs.h"

struct debugfs_cancellation {
    int (*cancel)(void *data);
    void *cancel_data;
};

#ifndef debugfs_remove
#define debugfs_remove(entry) ((void)0)
#endif

#define __user

/* Dummy struct to allow compilation */
struct debugfs_short_fops {
    void *read;
    void *llseek;
};

#define DEBUGFS_READONLY_FILE_FN(name, fmt, value) \
    static ssize_t name##_read(void *file, char *userbuf, size_t count) { return 0; }

#define DEBUGFS_READONLY_FILE_OPS(name) \
    static const struct debugfs_short_fops name##_ops = { NULL, NULL }

#define DEBUGFS_READONLY_FILE(name, fmt, value) \
    DEBUGFS_READONLY_FILE_FN(name, fmt, value); \
    DEBUGFS_READONLY_FILE_OPS(name)

#endif /* __LINUX_DEBUGFS_H_ */

