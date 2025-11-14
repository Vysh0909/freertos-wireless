#ifndef __LINUX_RHASHTABLE_H_
#define __LINUX_RHASHTABLE_H_
#include "types.h"

/* Minimal stub for rhashtable_params */
struct rhashtable_params {
	int nelem_hint;
    int automatic_shrinking;
    int key_len;
    int key_offset;
    int head_offset;
    void *hashfn;
     unsigned long max_size;
};

/* Minimal stub for rhashtable */
struct rhashtable {
    int nelems;
};

/* Dummy rhashtable functions for porting */
static inline void *rhashtable_lookup(struct rhashtable *tbl,
                                      const void *key,
                                      const struct rhashtable_params params)
{
    (void)tbl; (void)key; (void)params;
    return NULL;
}

static inline void *rhashtable_lookup_fast(struct rhashtable *tbl,
                                           const void *key,
                                           const struct rhashtable_params params)
{
    (void)tbl; (void)key; (void)params;
    return NULL;
}

static inline void rhashtable_remove_fast(struct rhashtable *tbl,
                                          void *node,
                                          const struct rhashtable_params params)
{
    (void)tbl; (void)node; (void)params;
}

#ifndef rhl_for_each_entry_rcu
#define rhl_for_each_entry_rcu(_pos, _tmp, _head, node) \
    for ((_pos) = (_head); (_pos) != NULL; (_pos) = NULL)
#endif

#ifndef rhl_for_each_entry
#define rhl_for_each_entry(_pos, _head, node) \
    for ((_pos) = (_head); (_pos) != NULL; (_pos) = NULL)
#endif

#endif /* __LINUX_RHASHTABLE_H_ */
