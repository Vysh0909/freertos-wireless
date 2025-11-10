#ifndef __PORTING_FS_H
#define __PORTING_FS_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h> 

#ifndef __user
#define __user
#endif

typedef long long loff_t;

struct file {
    void *private_data;
};

typedef ssize_t (*read_fn_t)(struct file *file, char *userbuf, size_t count, loff_t *ppos);

struct file_operations {
    read_fn_t read;
    int (*open)(struct file *file);
    loff_t (*llseek)(struct file *file, loff_t offset, int whence);
};

static inline int simple_open(struct file *file)
{
    (void)file;
    return 0;
}

static inline loff_t generic_file_llseek(struct file *file, loff_t offset, int whence)
{
    (void)file;
    (void)whence;
    return offset;
}

#endif /* __PORTING_FS_H */

