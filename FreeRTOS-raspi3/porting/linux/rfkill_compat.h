#ifndef __RFKILL_COMPAT_H__
#define __RFKILL_COMPAT_H__

/* Ensure RFKILL_HARD_BLOCK_SIGNAL is defined */
#ifndef RFKILL_HARD_BLOCK_SIGNAL
enum rfkill_hard_block_reasons {
    RFKILL_HARD_BLOCK_DEFAULT = 0,
    RFKILL_HARD_BLOCK_SIGNAL  = 1,
    RFKILL_HARD_BLOCK_POWER   = 2,
};
#define RFKILL_HARD_BLOCK_SIGNAL  RFKILL_HARD_BLOCK_SIGNAL
#endif

#endif /* __RFKILL_COMPAT_H__ */

