#ifndef __SKBUFF_H__
#define __SKBUFF_H__

/* Auto-generated stub header: skbuff.h */
#ifndef skb_queue_walk_safe
#define skb_queue_walk_safe(queue, skb, tmp) while (0)
#endif

#ifndef skb_list_walk_safe
#define skb_list_walk_safe(skb, head, tmp) \
    for ((skb) = (head); (skb) != NULL; (skb) = (skb)->next)
#endif

#define skb_queue_walk(queue, skb) for ((skb) = NULL; (skb) != NULL; (skb) = NULL)

#ifndef SKBTX_WIFI_STATUS
#define SKBTX_WIFI_STATUS 0x08
#endif

#ifndef NET_SKB_PAD
#define NET_SKB_PAD 0
#endif

#ifndef CHECKSUM_UNNECESSARY
#define CHECKSUM_UNNECESSARY 0
#endif

#ifndef PACKET_OTHERHOST
#define PACKET_OTHERHOST 1
#endif

#ifndef ETH_P_802_2
#define ETH_P_802_2 0x0003
#endif

#ifndef ETH_P_802_3
#define ETH_P_802_3 0x0001
#endif

#ifndef ETH_P_PREAUTH
#define ETH_P_PREAUTH 0x88C7
#endif

#ifndef EACCES
#define EACCES 13
#endif

#ifndef SKB_DROP_REASON_SUBSYS_MASK
#define SKB_DROP_REASON_SUBSYS_MASK 0xFFFF
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

struct skb_shared_hwtstamps {
    int hwtstamp;
};

static inline struct skb_shared_hwtstamps *skb_hwtstamps(void *skb)
{
    static struct skb_shared_hwtstamps stub;
    return &stub;
}
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
    unsigned int pkt_type;
     int ip_summed;
     void (*destructor)(struct sk_buff *skb);  /* function pointer stub */
    int wifi_acked_valid;
    int wifi_acked;
    struct skb_shared_info *shinfo;
     int encapsulation;
     unsigned int truesize;
     struct sk_buff *next;
};

struct skb_shared_info {
    unsigned int nr_frags;
    skb_frag_t frags[16]; /* arbitrary small number */
     unsigned int tx_flags;
     struct sk_buff *frag_list;
      unsigned int gso_size;
};

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb)
{
    static struct skb_shared_info dummy_info = {0};
    return &dummy_info;
}

static inline u8 *skb_tail_pointer(const struct sk_buff *skb)
{
    return skb->data + skb->len;
}

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

#endif /* __SKBUFF_H__ */
