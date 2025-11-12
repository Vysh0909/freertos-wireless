#ifndef _SYSFS_STUBS_H
#define _SYSFS_STUBS_H

#include <stddef.h>  /* For NULL */
#include <stdint.h>  /* For standard integer types */
#include <stdbool.h>

#ifndef hweight16
#define hweight16(x) (__builtin_popcount((unsigned short)(x)))
#endif

#ifndef is_multicast_ether_addr
#define is_multicast_ether_addr(addr) ((addr)[0] & 0x01)
#endif

#ifndef get_unaligned_be16
#define get_unaligned_be16(p) \
    (((const unsigned char *)(p))[0] << 8 | ((const unsigned char *)(p))[1])
#endif

#ifndef ether_addr_to_u64
static inline unsigned long long ether_addr_to_u64(const unsigned char *addr) {
    unsigned long long val = 0;
    for (int i = 0; i < 6; i++)
        val = (val << 8) | addr[i];
    return val;
}
#endif

#ifndef u64_to_ether_addr
static inline void u64_to_ether_addr(unsigned long long val, unsigned char *addr) {
    for (int i = 5; i >= 0; i--) {
        addr[i] = val & 0xFF;
        val >>= 8;
    }
}
#endif

/* Bitfield helpers */
#ifndef u16_get_bits
#define u16_get_bits(val, mask) ((val & (mask)) >> __builtin_ctz(mask))
#endif


/* Branch prediction */
#ifndef unlikely
#define unlikely(x) (x)
#endif

/* SKB stubs for FreeRTOS */
#ifndef skb_is_nonlinear
#define skb_is_nonlinear(skb) 0
#endif

#ifndef skb_network_offset
#define skb_network_offset(skb) 0
#endif

#ifndef skb_network_header
#define skb_network_header(skb) ((unsigned char *)(skb)->data)
#endif


/* Define ssize_t if missing */
#ifndef _SSIZE_T_DEFINED
typedef long ssize_t;
#define _SSIZE_T_DEFINED
#endif
#define ATTRIBUTE_GROUPS(name)
/* Stub for ieee80211 sysfs attribute groups */
//static const void *ieee80211_groups[] = { NULL };
static const void *ieee80211_groups[] __attribute__((unused)) = { NULL };

/* Stub for net namespace type operations */
struct kobj_ns_type_operations {
    const char *name;
};
static const struct kobj_ns_type_operations net_ns_type_operations = {
    .name = "net_ns_stub",
};


#endif /* _SYSFS_STUBS_H */

