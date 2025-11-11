#ifndef __RFKILL_COMPAT_H__
#define __RFKILL_COMPAT_H__


#ifndef rfkill_pause_polling
#define rfkill_pause_polling(rfkill) ((void)0)
#endif

#ifndef ASSERT_RTNL
#define ASSERT_RTNL() ((void)0)
#endif

/* Ensure RFKILL_HARD_BLOCK_SIGNAL is defined */
#ifndef RFKILL_HARD_BLOCK_SIGNAL
enum rfkill_hard_block_reasons {
    RFKILL_HARD_BLOCK_DEFAULT = 0,
    RFKILL_HARD_BLOCK_SIGNAL  = 1,
    RFKILL_HARD_BLOCK_POWER   = 2,
};
#define RFKILL_HARD_BLOCK_SIGNAL  RFKILL_HARD_BLOCK_SIGNAL
#endif

struct rfkill_ops {
    int (*query)(void *data, int id);
    int (*set)(void *data, int id, bool blocked);
    void (*set_block)(void);
    void (*poll)(void *data);
};

#define RFKILL_TYPE_WLAN 0

static inline void *rfkill_alloc(const char *name, void *dev, int type,
                                 struct rfkill_ops *ops, void *data) {
    return NULL; // Dummy
}


#endif /* __RFKILL_COMPAT_H__ */

