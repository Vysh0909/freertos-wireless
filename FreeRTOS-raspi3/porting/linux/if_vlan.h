#ifndef __IF_VLAN_H__
#define __IF_VLAN_H__

/* Auto-generated stub header: if_vlan.h */

#include <stdint.h>
#include "types.h"

/* VLAN priority bits (3 bits) */
#define VLAN_PRIO_MASK   0xE000
#define VLAN_PRIO_SHIFT  13

#ifndef VLAN_N_VID
#define VLAN_N_VID 4096
#endif

#ifndef VLAN_ETH_HLEN
#define VLAN_ETH_HLEN 18
#endif

struct vlan_ethhdr {
    __u8  h_dest[ETH_ALEN];
    __u8  h_source[ETH_ALEN];
    __be16 h_vlan_proto;
    __be16 h_vlan_TCI;
    __be16 h_vlan_encapsulated_proto;
} __attribute__((packed));

#endif /* __IF_VLAN_H__ */
