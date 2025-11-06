#ifndef __WIPHY_COMPAT_H__
#define __WIPHY_COMPAT_H__

/* Dummy guard macro to allow compilation */
#ifndef guard
#define guard(x) wiphy_compat_##x
#endif

/* Dummy guard function for wiphy */
static inline void wiphy_compat_wiphy(void *w)
{
    (void)w; /* No-op to satisfy compilation */
}

#endif /* __WIPHY_COMPAT_H__ */

