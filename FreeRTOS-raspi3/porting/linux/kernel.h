#ifndef __KERNEL_H__
#define __KERNEL_H__

/* Auto-generated stub header: kernel.h */

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

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

#endif /* __KERNEL_H__ */
