#ifndef __LINUX_SCATTERLIST_H_
#define __LINUX_SCATTERLIST_H_

#include "types.h" // Ensure you have basic types like u32, u64
typedef unsigned long long dma_addr_t;
struct scatterlist {
    unsigned long   page_link;
    unsigned int    offset;     /* low 24 bits */
    unsigned int    length;     /* middle 24 bits */
    dma_addr_t      dma_address;/* high 32 bits (if not 64 bit) */
    __u32           dma_length;
    void *address;
};

#endif /* __LINUX_SCATTERLIST_H_ */
