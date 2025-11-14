#ifndef __PORTING_FS_H
#define __PORTING_FS_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h> 

#ifndef __user
#define __user
#endif

#ifndef fs_initcall
#define fs_initcall(fn)    /* nothing */
#endif

#ifndef module_exit
#define module_exit(fn)    static void fn(void)
#endif

#if 0
static void __exit cfg80211_exit(void) { }
#endif
typedef long long loff_t;
struct inode {
    void *i_private;
};

struct file {
    void *private_data;
    void *dummy;
};

typedef ssize_t (*read_fn_t)(struct file *file, char *userbuf, size_t count, loff_t *ppos);

struct file_operations {
    read_fn_t read;
    int (*open)(struct file *file);
    loff_t (*llseek)(struct file *file, loff_t offset, int whence);
    void *owner;                        /* Dummy for .owner = THIS_MODULE */
    int (*release)(struct inode *, struct file *);
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

static inline loff_t default_llseek(struct file *file, loff_t offset, int whence)
{
    (void)file; (void)whence;
    return offset;
}


#endif /* __PORTING_FS_H */

