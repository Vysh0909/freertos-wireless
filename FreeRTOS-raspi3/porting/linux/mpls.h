#ifndef __MPLS_H__
#define __MPLS_H__

/* Auto-generated stub header: mpls.h */

/* Minimal MPLS label structure */
struct mpls_label {
    __be32 entry;
};

/* MPLS field masks and shifts (from kernel definitions) */
#define MPLS_LS_LABEL_MASK   0xFFFFF000
#define MPLS_LS_TC_MASK      0x00000E00
#define MPLS_LS_S_MASK       0x00000100
#define MPLS_LS_TTL_MASK     0x000000FF

#define MPLS_LS_LABEL_SHIFT  12
#define MPLS_LS_TC_SHIFT     9
#define MPLS_LS_S_SHIFT      8
#define MPLS_LS_TTL_SHIFT    0

#endif /* __MPLS_H__ */
