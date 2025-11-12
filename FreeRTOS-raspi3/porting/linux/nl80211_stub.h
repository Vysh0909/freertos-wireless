#ifndef __NL80211_STUB_H__
#define __NL80211_STUB_H__

/* Mark unused arrays as maybe_unused to suppress warnings */
#ifndef UNUSED_POLICY_ARRAY
#define UNUSED_POLICY_ARRAY __attribute__((unused))
#endif

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


#endif /* __NL80211_STUB_H__ */

