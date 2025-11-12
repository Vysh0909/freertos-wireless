#ifndef __LINUX_DEBUGFS_H_
#define __LINUX_DEBUGFS_H_

struct debugfs_cancellation {
    int (*cancel)(void *data);
    void *cancel_data;
};

#ifndef debugfs_remove
#define debugfs_remove(entry) ((void)0)
#endif

#endif /* __LINUX_DEBUGFS_H_ */

