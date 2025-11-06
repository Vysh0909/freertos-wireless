#ifndef __WAIT_COMPAT_H__
#define __WAIT_COMPAT_H__

typedef struct wait_queue_head {
    void *head;
} wait_queue_head_t;

static inline void init_waitqueue_head(void *q) {
    // do nothing
}

#endif /* __WAIT_COMPAT_H__ */

