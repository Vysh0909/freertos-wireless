#ifndef __KERNEL_H__
#define __KERNEL_H__

/* Auto-generated stub header: kernel.h */

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "crypto.h"
#include "types.h"

/* ---- Basic Macros ---- */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

#ifndef struct_size
#define struct_size(p, member, n) (sizeof(*(p)) + (n) * sizeof((p)->member[0]))
#endif


#define GFP_ATOMIC 0
#define HZ 1000
#define MSEC_PER_SEC 1000

#ifndef USEC_PER_SEC
#define USEC_PER_SEC 1000000
#endif


/* ---- Struct Group Stub ---- */
/*
 * The real kernel __struct_group groups related members into a named
 * sub-structure and optionally provides an anonymous struct for direct access.
 * For user-space porting, a simple inline struct works fine.
 */
#ifndef __struct_group
#define __struct_group(TAG, NAME, ATTRS, MEMBERS...) \
    struct TAG { MEMBERS } NAME;
#endif

/* ---- Static assert compatibility ---- */
#ifndef static_assert
#define static_assert _Static_assert
#endif

/* ---- get_unaligned_le16/le32 helpers ---- */
static inline uint16_t get_unaligned_le16(const void *p)
{
    const uint8_t *b = (const uint8_t *)p;
    return (uint16_t)b[0] | ((uint16_t)b[1] << 8);
}

static inline uint32_t get_unaligned_le32(const void *p)
{
    const uint8_t *b = (const uint8_t *)p;
    return (uint32_t)b[0] | ((uint32_t)b[1] << 8) |
           ((uint32_t)b[2] << 16) | ((uint32_t)b[3] << 24);
}

#ifndef fallthrough
#define fallthrough do {} while (0)
#endif

#ifndef min_t
#define min_t(type, x, y) \
    ({ type __min1 = (x); type __min2 = (y); __min1 < __min2 ? __min1 : __min2; })
#endif

#ifndef get_random_bytes
#include <stdlib.h>
static inline void get_random_bytes(void *buf, size_t len) {
    unsigned char *b = (unsigned char *)buf;
    for (size_t i = 0; i < len; i++)
        b[i] = rand() & 0xFF;
}
#endif

#ifndef read_pnet
#define read_pnet(x) NULL
#endif

#ifndef write_pnet
#define write_pnet(x,y) ((void)0)
#endif

struct netdev_hw_addr_list;
struct ethtool_stats;
struct net_device_path;
struct net_device_path_ctx;
struct napi_struct;
enum tc_setup_type;

struct ewma_mesh_fail_avg { int dummy; };
struct ewma_mesh_tx_rate_avg { int dummy; };
struct u64_stats_sync { int dummy; };
struct rhlist_head { int dummy; };
struct codel_params { int dummy; };
struct ewma_signal { int dummy; };
struct ewma_avg_signal { int dummy; };
struct hlist_head { int dummy; };
struct rhashtable { int dummy; };
struct fq_tin { 
	int backlog_packets; 
	unsigned long flows;
    unsigned long overlimit;
    unsigned long collisions;
    unsigned long tx_bytes;
    unsigned long tx_packets;
    unsigned long backlog_bytes;
};
struct codel_vars { int dummy; };
struct codel_stats {
	unsigned long drop_count;
        unsigned long ecn_mark;
};
struct idr { int dummy; };
struct ewma_beacon_signal { int dummy; };

/* --- New kernel struct stubs --- */
struct spinlock { int dummy; }; 
struct fq { 
	struct spinlock lock;
    int backlog_packets;
    unsigned long backlog;
    unsigned long memory_usage;
    unsigned long overlimit;
    unsigned long overmemory;
    unsigned long collisions;
    unsigned long flows_cnt;
    unsigned int limit;
    unsigned int memory_limit;
    unsigned int quantum;
    unsigned int tx_bytes;
    unsigned int tx_packets;
};

struct netdev_hw_addr_list { int count; };
struct tasklet_struct { int dummy; };
struct rhltable { int dummy; };
struct arc4_ctx { int dummy; };


/* --- Stub typedefs --- */
typedef int netdev_tx_t;

enum tc_setup_type {
    TC_SETUP_TYPE_DUMMY = 0
};

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node *prev;
};

/* Stub for rhash_head */
struct rhash_head {
    struct rhash_head *next;
};

/* --- Kernel annotations simplified --- */
#ifndef __percpu
#define __percpu
#endif

#ifndef IEEE80211_MAX_CHAINS
#define IEEE80211_MAX_CHAINS 4
#endif

#define SKB_CONSUMED 0
#define SKB_NOT_DROPPED_YET 1
#define SKB_DROP_REASON_SUBSYS_MAC80211_MONITOR 0
#define SKB_DROP_REASON_SUBSYS_MAC80211_UNUSABLE 0
#define SKB_DROP_REASON_SUBSYS_SHIFT 0
//#define DECLARE_STATIC_KEY_FALSE(x) int x = 0
#ifndef BITS_PER_LONG
#define BITS_PER_LONG 64
#endif

#ifndef IEEE80211_MAX_AID
#define IEEE80211_MAX_AID 2007
#endif

#ifndef BITS_TO_LONGS
#define BITS_TO_LONGS(x) (((x) + BITS_PER_LONG - 1) / BITS_PER_LONG)
#endif

#ifndef __maybe_unused
#define __maybe_unused
#endif

#ifndef KERN_DEBUG
#define KERN_DEBUG 0
#endif


struct static_key_stub {
    int enabled;
};

#define DECLARE_STATIC_KEY_FALSE(name) \
    struct { struct static_key_stub key; } name = { { 0 } }

static inline bool static_key_false(struct static_key_stub *key)
{
    (void)key;
    return false;
}


#endif /* __KERNEL_H__ */
