#ifndef __SKBUFF_H__
#define __SKBUFF_H__

/* Auto-generated stub header: skbuff.h */
struct sk_buff {
    void *data;
    unsigned int len;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

#endif /* __SKBUFF_H__ */
