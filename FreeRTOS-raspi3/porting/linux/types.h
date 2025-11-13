#ifndef __LINUX_TYPES_H_
#define __LINUX_TYPES_H_


/* Standard includes */
#include <stdint.h>
#include <stddef.h>   /* for NULL */
#include <stdbool.h>
#include <limits.h>   /* for CHAR_BIT */
#include "skbuff.h"
#include "kernel.h"
#include "if_ether.h"

#define U32_MAX 0xFFFFFFFFU

/* Basic kernel-style integer types */
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;

typedef int8_t    s8;
typedef int16_t   s16;
typedef int32_t   s32;
typedef int64_t   s64;

/* Double-underscore kernel style */
typedef uint8_t   __u8;
typedef uint16_t  __u16;
typedef uint32_t  __u32;
typedef uint64_t  __u64;

typedef int8_t    __s8;
typedef int16_t   __s16;
typedef int32_t   __s32;
typedef int64_t   __s64;

/* Little/Big endian placeholder types (assume host endianness) */
typedef uint16_t  __le16;
typedef uint32_t  __le32;
typedef uint64_t  __le64;

typedef uint16_t  __be16;
typedef uint32_t  __be32;
typedef uint64_t  __be64;
typedef long ssize_t;
typedef unsigned int gfp_t;
typedef int atomic_t;
#define ATOMIC_INIT(x) (x)

typedef unsigned long long netdev_features_t;

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

/* Common macros used by kernel headers */

/* packed / aligned helpers */
#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

#ifndef __aligned
#define __aligned(x) __attribute__((__aligned__(x)))
#endif

/* DECLARE_FLEX_ARRAY used in kernel headers */
#ifndef DECLARE_FLEX_ARRAY
#define DECLARE_FLEX_ARRAY(type, name) type name[0]
#endif

/* struct_group compatibility (very small shim) */
#ifndef struct_group
/* Usage in kernel headers: struct_group(name, members...) */
#define struct_group(name, ...) \
    struct { __VA_ARGS__ } name
#endif

/* struct_group_attr */
#ifndef struct_group_attr
#define struct_group_attr(name, attr, ...) \
    struct attr { __VA_ARGS__ } name
#endif

/* NULL guaranteed from <stddef.h>, but define fallback */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Field extraction helpers
 * FIELD_GET(mask, reg) returns the field bits right-shifted to LSB.
 * Works for masks that are contiguous bitfields (typical kernel masks).
 */
#ifndef FIELD_GET
#define FIELD_GET(mask, reg) (((reg) & (mask)) / ((mask) & - (mask)))
#endif

/* Provide common _get_bits aliases used by ieee80211 etc. */
#ifndef le16_get_bits
#define le16_get_bits(val, mask) FIELD_GET(mask, (val))
#endif

#ifndef u8_get_bits
#define u8_get_bits(val, mask) FIELD_GET(mask, (val))
#endif

/* Endian conversion stubs: out-of-kernel builds can treat them as identity.
 * If you later need to convert between host and little-endian, replace these.
 */
#ifndef cpu_to_le16
#define cpu_to_le16(x) ((uint16_t)(x))
#endif
#ifndef le16_to_cpu
#define le16_to_cpu(x) ((uint16_t)(x))
#endif
#ifndef le32_to_cpu
#define le32_to_cpu(x) ((uint32_t)(x))
#endif
#ifndef cpu_to_le32
#define cpu_to_le32(x) ((uint32_t)(x))
#endif

/* Bit population (hweight8) - count bits in 8-bit value */
#ifndef hweight8
static inline unsigned int hweight8(unsigned int w)
{
    /* rely on builtin popcount (works for any unsigned int) */
    return __builtin_popcount(w & 0xffu);
}
#endif

/* DIV_ROUND_UP macro used in kernel code */
#ifndef DIV_ROUND_UP
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#endif

/* A few helper macros often used */
#ifndef BIT
#define BIT(n) (1UL << (n))
#endif

/* If ETH_ALEN (MAC address length) missing */
#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

/* FALLBACK for u8/u16 masking constants operations - safe defaults */
#ifndef le16_to_cpu
#define le16_to_cpu(x) ((uint16_t)(x))
#endif

/* le16/32 etc. already defined above; ensure all used aliases exist */
#ifndef le32_get_bits
#define le32_get_bits(val, mask) FIELD_GET(mask, (val))
#endif

#ifndef offsetofend
#define offsetofend(TYPE, MEMBER) (offsetof(TYPE, MEMBER) + sizeof(((TYPE *)0)->MEMBER))
#endif

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

/* Kernel bool type if not defined */
#ifndef bool
typedef unsigned char bool;
#define true 1
#define false 0
#endif

/*enum dfs_region {
    DFS_UNSET = 0,
    DFS_FCC,
    DFS_ETSI,
    DFS_JP,
};

struct ieee80211_regdomain {
    enum dfs_region dfs_region;
};
*/
/*struct ieee80211_freq_range {
    u32 start_freq_khz;
    u32 end_freq_khz;
};
*/
#endif /* __LINUX_TYPES_H_ */
