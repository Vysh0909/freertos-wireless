#ifndef __LINUX_CRYPTO_H_
#define __LINUX_CRYPTO_H_

#define CRYPTO_ALG_ASYNC 0x00000004
struct crypto_async_request {
    void *data;
    void (*complete)(struct crypto_async_request *req, int res);
    int flags;
    char ctx_padding[8];
};
#endif /* __LINUX_CRYPTO_H_ */
