#ifndef __CRYPTO_AEAD_H_
#define __CRYPTO_AEAD_H_

#include "../linux/scatterlist.h"
#include "../linux/crypto.h"

struct aead_request {
        struct crypto_async_request base;
    struct scatterlist *src;
    struct scatterlist *dst;
    void *iv;
    unsigned int assoclen;
    unsigned int cryptlen;
    char __ctx_padding[16];
};

#endif /* __CRYPTO_AEAD_H_ */
