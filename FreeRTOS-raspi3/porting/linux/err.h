#ifndef __ERR_H__
#define __ERR_H__

/* Auto-generated stub header: err.h */

#define EPERM        1
#define ENOENT       2
#define ESRCH        3
#define EINTR        4
#define EIO          5
#define ENXIO        6
#define E2BIG        7
#define ENOEXEC      8
#define EBADF        9
#define ECHILD      10
#define EAGAIN      11
#define ENOMEM      12
#define EFAULT     14
#define EBUSY       16
#define EEXIST 17
#define EALREADY   114
#define EINPROGRESS   115
#define ENODEV     19
#define EILSEQ      84
#define EINVAL      22
#define ENOSPC      28
#define ERANGE      34
#define ENODATA     61
#define ENOLINK      67
#define EMSGSIZE 90  /* Message too long */
#define EPROTO   71  /* Protocol error */
#define ENOTUNIQ 76
#define ENETDOWN 100  /* Network is down */
#define ENOBUFS 105
#define ENOTCONN 107

#ifndef ERFKILL
#define ERFKILL 100
#endif

#ifndef EOPNOTSUPP
#define EOPNOTSUPP 95
#endif

#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL 99
#endif

#ifndef EHOSTUNREACH
#define EHOSTUNREACH 113
#endif

#ifndef pr_err
#define pr_err(fmt, ...) ((void)0)
#endif

#ifndef __exit
#define __exit
#endif
#ifndef __init
#define __init
#endif

#endif /* __ERR_H__ */
