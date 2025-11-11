#ifndef __BUG_H__
#define __BUG_H__

#include "compiler.h"
#include "rfkill_compat.h"
#include "env_compat.h"
#include "wait_compat.h"
#include "time.h"
#include "jiffies.h"

#include <stdio.h>

#define WARN_ON(x) ({ \
    int __ret_warn_on = !!(x); \
    if (__ret_warn_on) \
        fprintf(stderr, "WARN_ON triggered: %s:%d\n", __FILE__, __LINE__); \
    __ret_warn_on; \
})

#endif /* __BUG_H__ */

