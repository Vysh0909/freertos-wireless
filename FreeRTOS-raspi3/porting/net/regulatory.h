#ifndef __REGULATORY_H__
#define __REGULATORY_H__

#include "../linux/module.h"
#include "../linux/net.h"

#ifndef REGULATORY_WIPHY_SELF_MANAGED
#define REGULATORY_WIPHY_SELF_MANAGED    0x01
#endif

#ifndef REGULATORY_CUSTOM_REG
#define REGULATORY_CUSTOM_REG            0x02
#endif

#ifndef REGULATORY_STRICT_REG
#define REGULATORY_STRICT_REG            0x04
#endif

#ifndef REGULATORY_COUNTRY_IE_FOLLOW_POWER
#define REGULATORY_COUNTRY_IE_FOLLOW_POWER 0x08
#endif

#ifndef REGULATORY_COUNTRY_IE_IGNORE
#define REGULATORY_COUNTRY_IE_IGNORE     0x10
#endif

#define REG_RULE(start, end, ...) {0}

#define mutex_lock(x)   ((void)0)
#define mutex_unlock(x) ((void)0)

struct mutex reg_regdb_apply_mutex; // define the mutex

enum reg_env {
    ENVIRON_ANY,
    ENVIRON_IND,
    ENVIRON_FCC,
    ENVIRON_ETSI,
    ENVIRON_GLOBAL
};

struct regulatory_request {
    int wiphy_idx;
    int initiator;
    char alpha2[2];
    bool intersect;
    bool processed;
    enum reg_env country_ie_env;
};


enum dfs_region {
    DFS_UNSET = 0,
    DFS_FCC,
    DFS_ETSI,
    DFS_JP,
};

struct ieee80211_reg_rule {
    int dummy;
};

struct ieee80211_regdomain {
	enum dfs_region dfs_region;
    int n_reg_rules;
    char alpha2[2];
    struct ieee80211_reg_rule reg_rules[];
};

#endif /* __REGULATORY_H__ */

