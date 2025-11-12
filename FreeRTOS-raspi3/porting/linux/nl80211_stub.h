#ifndef __NL80211_STUB_H__
#define __NL80211_STUB_H__

#include <stdint.h>
#include <stddef.h>

/* Mark unused arrays as maybe_unused to suppress warnings */
#ifndef UNUSED_POLICY_ARRAY
#define UNUSED_POLICY_ARRAY __attribute__((unused))
#endif

/*#define DEVICE_ATTR_RO(name)
#define ATTRIBUTE_GROUPS(x)
#define DEFINE_MUTEX(x)
#define DECLARE_WORK(a, b)
#define DECLARE_DELAYED_WORK(a,b)
#define DEFINE_SPINLOCK(x) 
*/
/* Safe macro stubs for non-Linux builds */
#define DEFINE_SPINLOCK(x)     struct {} __dummy_spinlock_##x
#define DEFINE_MUTEX(x)        struct {} __dummy_mutex_##x
#define DECLARE_WORK(name, fn) struct {} __dummy_work_##name
#define DECLARE_DELAYED_WORK(name, fn) struct {} __dummy_delayed_work_##name
#define DEVICE_ATTR_RO(name)   struct {} __dummy_dev_attr_##name
#define late_initcall(fn)      static void *__dummy_##fn = fn

/* genetlink family registration stubs */
static inline int genl_register_family(void *fam)
{
    (void)fam;
    return 0; /* stub: return success */
}

static inline void genl_unregister_family(void *fam)
{
    (void)fam;
}

/* netlink notifier registration stubs */
static inline int netlink_register_notifier(void *nb)
{
    (void)nb;
    return 0; /* stub: return success */
}

static inline void netlink_unregister_notifier(void *nb)
{
    (void)nb;
}

/* Stubs to avoid pointer-from-int and implicit declaration warnings */
static inline struct sk_buff *nlmsg_new(size_t size, int gfp) { return NULL; }
static inline struct nlattr *nla_nest_start_noflag(struct sk_buff *skb, int attr) { return NULL; }
static inline int nla_put_be32(struct sk_buff *skb, int attr, uint32_t value) { return 0; }
static inline uint32_t cpu_to_be32(uint32_t val) { return val; }


/* nla helpers */
static inline size_t nla_total_size(size_t payload) { return 0; }
static inline struct nlattr *nla_nest_start(struct sk_buff *skb, int attr) { return NULL; }
static inline struct nlattr *nla_reserve(struct sk_buff *skb, int attr, size_t len) { return NULL; }

/* endianness helpers */
static inline uint16_t be16_to_cpu(uint16_t val) { return val; }

/* skb helpers */
static inline int skb_copy_bits(struct sk_buff *skb, int offset, void *to, size_t len)
{
    (void)skb;
    (void)offset;
    (void)to;
    (void)len;
    return 0; /* simulate success */
}

/* RCU / concurrency stubs */
#define READ_ONCE(x) (x)
//static inline void *rcu_dereference(void *p) { return p; }
static inline void *wiphy_dereference(void *w, void *p) { return p; }

/* bit helpers */
static inline int __ffs(unsigned int mask) { return 0; }

/* Ethernet stub */
static inline struct ethhdr *eth_hdr(struct sk_buff *skb) { return NULL; }


#endif /* __NL80211_STUB_H__ */

