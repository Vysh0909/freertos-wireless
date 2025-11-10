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

#endif /* __ETHTOOL_H__ */

