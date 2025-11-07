#ifndef __IF_ETHER_H__
#define __IF_ETHER_H__

/* Auto-generated stub header: if_ether.h */
#ifndef ETH_P_TDLS
#define ETH_P_TDLS 0x2A0  /* Tunneled Direct Link Setup */
#endif

#ifndef ETH_P_AARP
#define ETH_P_AARP 0x80F3 /* Appletalk AARP */
#endif

#ifndef ETH_P_IPX
#define ETH_P_IPX  0x8137 /* IPX over DIX */
#endif

#define ETH_ALEN 6
typedef uint16_t __be16;
struct ethhdr {
    unsigned char   h_dest[ETH_ALEN];
    unsigned char   h_source[ETH_ALEN];
    __be16          h_proto;
};

#endif /* __IF_ETHER_H__ */
