#ifndef __LINUX_INTERRUPT_H_
#define __LINUX_INTERRUPT_H_

#include "types.h"

struct tasklet_struct {
    void (*func)(unsigned long);
    unsigned long data;
};

#define from_tasklet(var, t, member)  (var)
#define tasklet_init(t, func, data)   ((void)0)
#define tasklet_schedule(t)           ((void)0)
#define tasklet_kill(t)               ((void)0)

#endif /* __LINUX_INTERRUPT_H_ */
