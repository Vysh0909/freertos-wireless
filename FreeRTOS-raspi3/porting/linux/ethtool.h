#ifndef __ETHTOOL_H__
#define __ETHTOOL_H__

/* Auto-generated stub header: ethtool.h */

#include <stddef.h>
#include "types.h"

/* Define standard lengths used by ethtool structures */
#ifndef ETHTOOL_FWVERS_LEN
#define ETHTOOL_FWVERS_LEN 32
#endif

#ifndef ETHTOOL_BUSINFO_LEN
#define ETHTOOL_BUSINFO_LEN 32
#endif

/* Basic ethtool command IDs (optional minimal set) */
#define ETHTOOL_GDRVINFO 0x00000003
#define ETH_GSTRING_LEN 32
#define ETH_SS_STATS    1

struct ethtool_drvinfo {
    __u32   cmd;
    char    driver[32];
    char    version[32];
    char    fw_version[ETHTOOL_FWVERS_LEN];
    char    bus_info[ETHTOOL_BUSINFO_LEN];
    char    reserved1[32];
    char    reserved2[12];
};
struct kernel_ethtool_ringparam;
struct ethtool_ringparam {
    u32 rx_max_pending;
    u32 rx_mini_max_pending;
    u32 rx_jumbo_max_pending;
    u32 tx_max_pending;
    u32 rx_pending;
    u32 rx_mini_pending;
    u32 rx_jumbo_pending;
    u32 tx_pending;
};

struct ethtool_regs {
    unsigned int version;
    unsigned int len;
};

/* Minimal stub for ethtool_ops */
struct ethtool_ops {
    void (*get_drvinfo)(void);
    int  (*get_regs_len)(void);
    void (*get_regs)(void);
    int  (*get_link)(void);
    void (*get_ringparam)(void);
    void (*set_ringparam)(void);
    void (*get_strings)(void);
    void (*get_ethtool_stats)(void);
    int  (*get_sset_count)(void);
};

/* ---- Stub function definitions for cfg80211 + ethtool ops ---- */
#ifndef CONFIG_CFG80211
static inline void cfg80211_get_drvinfo(struct net_device *dev,
                                        struct ethtool_drvinfo *info)
{
    /* not implemented in this port */
}
#endif

static inline int ethtool_op_get_link(void)
{
    /* always return link up (1) or just 0 to compile */
    return 0;
}

#endif /* __ETHTOOL_H__ */

