#ifndef __LINUX_TIMER_H_
#define __LINUX_TIMER_H_

#ifndef timer_setup
#define timer_setup(timer, func, flags) ((void)0)
#endif

#define from_timer(var, callback_timer, timer_fieldname) \
    container_of(callback_timer, typeof(*var), timer_fieldname)

#endif /* __LINUX_TIMER_H_ */
