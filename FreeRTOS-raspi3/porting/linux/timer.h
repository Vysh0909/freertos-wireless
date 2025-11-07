#ifndef __LINUX_TIMER_H_
#define __LINUX_TIMER_H_

#define from_timer(var, callback_timer, timer_fieldname) \
    container_of(callback_timer, typeof(*var), timer_fieldname)

#endif /* __LINUX_TIMER_H_ */
