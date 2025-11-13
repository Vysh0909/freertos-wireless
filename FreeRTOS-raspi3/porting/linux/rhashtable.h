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

#endif /* __LINUX_RHASHTABLE_H_ */
