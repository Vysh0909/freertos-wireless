#ifndef __LINUX_BYTEORDER_H
#define __LINUX_BYTEORDER_H

#include <stdint.h>

/* No-op for host byte order (simplifies user-space builds) */
#define htons(x)  (x)
#define ntohs(x)  (x)
#define htonl(x)  (x)
#define ntohl(x)  (x)

#endif /* __LINUX_BYTEORDER_H */

