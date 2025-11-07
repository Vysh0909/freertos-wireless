#ifndef __REGULATORY_H__
#define __REGULATORY_H__


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

#endif /* __REGULATORY_H__ */

