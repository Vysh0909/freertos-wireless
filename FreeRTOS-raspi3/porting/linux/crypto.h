#ifndef __LINUX_CRYPTO_H_
#define __LINUX_CRYPTO_H_

#include "atomic.h"
#include "ktime.h"

#define CRYPTO_ALG_ASYNC 0x00000004
#define AES_BLOCK_SIZE 16
struct shash_desc {
        /* Use a simple void* to represent the transform handle */
    void *tfm;
    /* Context area, fixed size for simplicity */
    char shash_ctx[16];
};
#define SHASH_DESC_ON_STACK(desc, tfm) \
    char __desc_data[sizeof(struct shash_desc) + crypto_shash_descsize(tfm)] \
	    __attribute__ ((aligned(__alignof__(struct shash_desc)))); \
	struct shash_desc *desc = (struct shash_desc *)__desc_data;
struct crypto_async_request {
    void *data;
    void (*complete)(struct crypto_async_request *req, int res);
    int flags;
    char ctx_padding[8];
};

#endif /* __LINUX_CRYPTO_H_ */
