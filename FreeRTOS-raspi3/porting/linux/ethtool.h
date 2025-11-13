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

struct ethtool_drvinfo {
    __u32   cmd;
    char    driver[32];
    char    version[32];
    char    fw_version[ETHTOOL_FWVERS_LEN];
    char    bus_info[ETHTOOL_BUSINFO_LEN];
    char    reserved1[32];
    char    reserved2[12];
};

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

#endif /* __ETHTOOL_H__ */

