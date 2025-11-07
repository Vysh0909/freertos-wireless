#ifndef __REGULATORY_H__
#define __REGULATORY_H__

#include "../linux/module.h"
#include "../linux/net.h"

#ifndef max_t
#define max_t(type, a, b) ({ type __a = (a); type __b = (b); __a > __b ? __a : __b; })
#endif


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

#define REGULATORY_DISABLE_BEACON_HINTS  0x03


#define REG_RULE(start, end, ...) {0}
#define NL80211_USER_REG_HINT_USER 0
#define KHZ_PER_GHZ 1000000
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
    int user_reg_hint_type;
    int dfs_region;
     struct list_head list;
};


enum dfs_region {
    DFS_UNSET = 0,
    DFS_FCC,
    DFS_ETSI,
    DFS_JP,
};

struct ieee80211_wmm_ac {
    uint8_t cw_min;
    uint8_t cw_max;
    uint8_t aifsn;
    uint16_t cot;
};


struct ieee80211_wmm_rule {
    	 uint8_t padding[4]; // minimal stub, size depends on usage
	 struct ieee80211_wmm_ac client[4];
         struct ieee80211_wmm_ac ap[4];
};


struct ieee80211_reg_rule {
	 struct {
        int start_freq_khz;
        int end_freq_khz;
        int max_bandwidth_khz;
    } freq_range;

    struct {
        int max_antenna_gain;
        int max_eirp;
    } power_rule;
 
          int psd;
         unsigned int flags;
         unsigned int dfs_cac_ms;
	 struct ieee80211_wmm_rule wmm_rule;
	 bool has_wmm;
         int dummy;
};

struct ieee80211_regdomain {
	enum dfs_region dfs_region;
    int n_reg_rules;
    char alpha2[2];
    struct ieee80211_reg_rule reg_rules[];
};

struct ieee80211_freq_range {
    int start_freq_khz;
    int end_freq_khz;
    int max_bandwidth_khz;  /* add missing member */
};

/* For power rules */
struct ieee80211_power_rule {
    int max_eirp;          /* in dBm * 100 */
    int max_antenna_gain;  /* in dBi */
};

#endif /* __REGULATORY_H__ */

