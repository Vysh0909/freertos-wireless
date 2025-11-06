#ifndef __WIPHY_COMPAT_H__
#define __WIPHY_COMPAT_H__

typedef struct wiphy_work wiphy_work;

/* Dummy guard macro to allow compilation */
#ifndef guard
#define guard(x) wiphy_compat_##x
#endif

#ifndef scoped_guard
#define scoped_guard(x, y) if (1)
#endif

/* Dummy guard function for wiphy */
static inline void wiphy_compat_wiphy(void *w)
{
    (void)w; /* No-op to satisfy compilation */
}

#endif /* __WIPHY_COMPAT_H__ */

