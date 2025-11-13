#ifndef __SKBUFF_H__
#define __SKBUFF_H__

/* Auto-generated stub header: skbuff.h */
#ifndef skb_queue_walk_safe
#define skb_queue_walk_safe(queue, skb, tmp) while (0)
#endif

#include <stdbool.h> 
typedef uint16_t __be16;
typedef uint8_t   u8;

typedef struct page {
    void *addr;
} page;

typedef struct skb_frag {
    struct page *page;
    unsigned int page_offset;
    unsigned int size;
} skb_frag_t;

struct skb_shared_info {
    unsigned int nr_frags;
    skb_frag_t frags[16]; /* arbitrary small number */
};

struct sk_buff {
    u8 *data;
    unsigned int len;
    void *head;
     unsigned int data_len;
     struct net_device *dev;
    int priority;
    bool head_frag;
    __be16 protocol;
     unsigned char cb[48];
     void *sk;
    int portid;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

#endif /* __SKBUFF_H__ */
