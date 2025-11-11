#ifndef __COMPLETION_H__
#define __COMPLETION_H__

/* Auto-generated stub header: completion.h */
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
int pthread_cond_signal(pthread_cond_t *cond);

struct completion {
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int done;
};

static inline void init_completion(struct completion *x)
{
    pthread_mutex_init(&x->lock, NULL);
    pthread_cond_init(&x->cond, NULL);
    x->done = 0;
}

static inline void complete(struct completion *x)
{
    pthread_mutex_lock(&x->lock);
    x->done = 1;
    pthread_cond_signal(&x->cond);
    pthread_mutex_unlock(&x->lock);
}

#endif /* __COMPLETION_H__ */
