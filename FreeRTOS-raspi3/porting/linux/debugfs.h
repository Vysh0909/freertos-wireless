#ifndef __LINUX_DEBUGFS_H_
#define __LINUX_DEBUGFS_H_

struct debugfs_cancellation {
    int (*cancel)(void *data);
    void *cancel_data;
};

#endif /* __LINUX_DEBUGFS_H_ */

