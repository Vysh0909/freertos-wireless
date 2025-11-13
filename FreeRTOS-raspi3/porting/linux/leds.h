#ifndef __LINUX_LEDS_H_
#define __LINUX_LEDS_H_

#define LED_OFF   0
#define LED_FULL  1

struct led_trigger {
    const char *name;
    void (*activate)(struct led_trigger *t);
    void (*deactivate)(struct led_trigger *t);
};

struct led_classdev {
    struct led_trigger *trigger;
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
	(void)t;
    	(void)event;
}

static inline int led_trigger_register_simple(const char *name,
                                              struct led_trigger **trigger)
{
    if (trigger)
        *trigger = NULL;
    (void)name;
    return 0;
}

static inline void led_trigger_unregister_simple(struct led_trigger *trigger)
{
    (void)trigger;
}

#endif /* __LINUX_LEDS_H_ */
