#ifndef __BITOPS_H__
#define __BITOPS_H__

/* Auto-generated stub header: bitops.h */

#ifndef BIT
#define BIT(nr) (1UL << (nr))
#endif

#define for_each_set_bit(bit, addr, size)                \
    for ((bit) = find_first_bit((addr), (size));         \
         (bit) < (size);                                 \
         (bit) = find_next_bit((addr), (size), (bit) + 1))

#endif /* __BITOPS_H__ */
