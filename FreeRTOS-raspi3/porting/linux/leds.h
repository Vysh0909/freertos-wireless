#ifndef __LINUX_LEDS_H_
#define __LINUX_LEDS_H_

struct led_trigger {
    const char *name;
};

/* Stub macros and functions (no-ops) */
static inline int led_trigger_register(struct led_trigger *t)
{
    return 0;
}

static inline void led_trigger_unregister(struct led_trigger *t)
{
}

static inline void led_trigger_event(struct led_trigger *t, int event)
{
}
#endif /* __LINUX_LEDS_H_ */
