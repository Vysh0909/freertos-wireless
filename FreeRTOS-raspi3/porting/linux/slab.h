#ifndef __SLAB_H__
#define __SLAB_H__

/* Auto-generated stub header: slab.h */
#include "fs.h"
#include "mm.h"
#include "completion.h"
#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0

static inline void *kzalloc(size_t size, int flags)
{
    (void)flags;
    void *ptr = malloc(size);
    if (ptr)
        memset(ptr, 0, size);
    return ptr;
}

static inline void kfree(void *ptr)
{
    free(ptr);
}
#endif /* __SLAB_H__ */
