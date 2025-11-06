#ifndef __IF_ETHER_H__
#define __IF_ETHER_H__

/* Auto-generated stub header: if_ether.h */
#ifndef ETH_P_TDLS
#define ETH_P_TDLS 0x2A0  /* Tunneled Direct Link Setup */
#endif


#define ETH_ALEN 6

struct ethhdr {
    unsigned char   h_dest[ETH_ALEN];
    unsigned char   h_source[ETH_ALEN];
    __be16          h_proto;
};

#endif /* __IF_ETHER_H__ */
