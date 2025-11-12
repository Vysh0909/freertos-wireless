#ifndef __WIRELESS_H__
#define __WIRELESS_H__

/* Auto-generated stub header: wireless.h */

#ifndef BIT_ULL
#define BIT_ULL(x) (1ULL << (x))
#endif

#define IW_MLME_DEAUTH     0
#define IW_MLME_DISASSOC   1
#define IW_ESSID_MAX_SIZE 32
#define IW_MODE_AUTO       0   /* Let the driver decide */
#define IW_MODE_ADHOC      1   /* Independent BSS (Ad-hoc) */
#define IW_MODE_INFRA      2   /* Managed (Infrastructure) */
#define IW_MODE_MASTER     3   /* Master/Access Point */
#define IW_MODE_REPEAT     4   /* Repeater mode */
#define IW_MODE_SECOND     5   /* Secondary/repeater AP */
#define IW_MODE_MONITOR    6   /* Passive monitor mode */
#define IW_MODE_MESH       7   /* Mesh mode (if needed) */

#ifndef WIRELESS_EXT
#define WIRELESS_EXT 22
#endif

#define IW_RETRY_LIMIT            0x0001
#define IW_QUAL_NOISE_INVALID     0x02
#define IW_QUAL_DBM               0x08
#define IW_QUAL_QUAL_UPDATED      0x10
#define IW_QUAL_LEVEL_UPDATED     0x20

#define IW_ENC_CAPA_CIPHER_TKIP   0x0001
#define IW_ENC_CAPA_WPA           0x0002
#define IW_ENC_CAPA_CIPHER_CCMP   0x0004
#define IW_ENC_CAPA_WPA2          0x0008

#define IW_MAX_FREQUENCIES        32
#define IW_SCAN_CAPA_ESSID        0x01

#define SIOCGIWAP                 0x8B15
#define SIOCGIWSCAN               0x8B19

#ifndef SIOCGIWNAME
#define SIOCSIWFREQ        0x8B04
#define SIOCGIWFREQ        0x8B05
#define SIOCSIWMODE        0x8B06
#define SIOCGIWMODE        0x8B07
#define SIOCGIWRANGE       0x8B0B
#define SIOCSIWAP          0x8B14
#define SIOCGIWAP          0x8B15
#define SIOCSIWMLME        0x8B16
#define SIOCSIWESSID       0x8B1A
#define SIOCGIWESSID       0x8B1B
#define SIOCSIWRATE        0x8B20
#define SIOCGIWRATE        0x8B21
#define SIOCSIWRTS         0x8B22
#define SIOCGIWRTS         0x8B23
#define SIOCSIWFRAG        0x8B24
#define SIOCGIWFRAG        0x8B25
#define SIOCSIWTXPOW       0x8B26
#define SIOCGIWTXPOW       0x8B27
#define SIOCSIWRETRY       0x8B28
#define SIOCGIWRETRY       0x8B29
#define SIOCSIWENCODE      0x8B2A
#define SIOCGIWENCODE      0x8B2B
#define SIOCSIWPOWER       0x8B2C
#define SIOCGIWPOWER       0x8B2D
#define SIOCSIWGENIE       0x8B30
#define SIOCSIWAUTH        0x8B32
#define SIOCGIWAUTH        0x8B33
#define SIOCSIWENCODEEXT   0x8B34
#define SIOCSIWPMKSA       0x8B36
#define SIOCGIWSCAN        0x8B19
#define SIOCSIWSCAN        0x8B18
#define SIOCGIWNAME        0x8B01
#endif

#define IW_EVENT_CAPA_SIZE        8
#define IW_EVENT_CAPA_K_0         0
#define IW_EVENT_CAPA_K_1         1

#define IW_EVENT_CAPA_SET_KERNEL(x)  memset(x, 0, sizeof(x))
#define IW_EVENT_CAPA_SET(x, y)      do { } while (0)

#define IW_RETRY_LIFETIME 0x1000
#define IW_RETRY_TYPE     0x4000
#define IW_RETRY_LONG     0x8000
#define IW_RETRY_SHORT    0x0800

/* ---------- Encoding flag constants ---------- */
#define IW_ENCODE_INDEX        0x00FF
#define IW_ENCODE_FLAGS        0xFF00
#define IW_ENCODE_MODE         0xF000
#define IW_ENCODE_DISABLED     0x8000
#define IW_ENCODE_ENABLED      0x0000
#define IW_ENCODE_NOKEY        0x4000

/* ---------- Encryption algorithm constants ---------- */
#define IW_ENCODE_ALG_NONE     0
#define IW_ENCODE_ALG_WEP      1
#define IW_ENCODE_ALG_TKIP     2
#define IW_ENCODE_ALG_CCMP     3
#define IW_ENCODE_ALG_AES_CMAC 4

#define IW_ENCODE_EXT_TX_SEQ_VALID     0x00000001
#define IW_ENCODE_EXT_RX_SEQ_VALID     0x00000002
#define IW_ENCODE_EXT_GROUP_KEY        0x00000004
#define IW_ENCODE_EXT_SET_TX_KEY       0x00000008

/* ---------- TX power flags ---------- */
#define IW_TXPOW_TYPE   0x00FF
#define IW_TXPOW_DBM    0x0000
#define IW_TXPOW_MWATT  0x0001
#define IW_TXPOW_RANGE  0x1000

/* === Legacy WEXT definitions (removed from modern kernels) === */
#ifndef IW_AUTH_ALG_OPEN_SYSTEM
#define IW_AUTH_ALG_OPEN_SYSTEM        0x00000001
#define IW_AUTH_ALG_SHARED_KEY         0x00000002
#define IW_AUTH_ALG_LEAP               0x00000004
#endif

#ifndef IW_AUTH_WPA_VERSION_WPA
#define IW_AUTH_WPA_VERSION_WPA        0x00000002
#define IW_AUTH_WPA_VERSION_WPA2       0x00000004
#define IW_AUTH_WPA_VERSION_DISABLED   0x00000001
#endif

#ifndef IW_AUTH_CIPHER_WEP40
#define IW_AUTH_CIPHER_WEP40           0x00000001
#define IW_AUTH_CIPHER_TKIP            0x00000002
#define IW_AUTH_CIPHER_CCMP            0x00000008
#define IW_AUTH_CIPHER_WEP104          0x00000010
#define IW_AUTH_CIPHER_AES_CMAC        0x00000020
#define IW_AUTH_CIPHER_NONE            0x00000040
#endif

#ifndef IW_AUTH_KEY_MGMT_802_1X
#define IW_AUTH_KEY_MGMT_802_1X        1
#define IW_AUTH_KEY_MGMT_PSK           2
#endif

#ifndef IW_AUTH_INDEX
#define IW_AUTH_INDEX                  0x0FFF
#define IW_AUTH_PRIVACY_INVOKED        1
#define IW_AUTH_WPA_VERSION            2
#define IW_AUTH_CIPHER_GROUP           3
#define IW_AUTH_KEY_MGMT               4
#define IW_AUTH_CIPHER_PAIRWISE        5
#define IW_AUTH_80211_AUTH_ALG         6
#define IW_AUTH_WPA_ENABLED            7
#define IW_AUTH_RX_UNENCRYPTED_EAPOL   8
#define IW_AUTH_DROP_UNENCRYPTED       9
#define IW_AUTH_MFP                   10
#endif

#ifndef IW_POWER_MODE
#define IW_POWER_MODE                  0x000F
#define IW_POWER_ON                    0
#define IW_POWER_ALL_R                 1
#define IW_POWER_TIMEOUT               2
#endif

#ifndef IW_QUAL_LEVEL_INVALID
#define IW_QUAL_LEVEL_INVALID          0x10
#define IW_QUAL_QUAL_INVALID           0x20
#endif

#ifndef IW_PMKSA_ADD
#define IW_PMKSA_ADD                   1
#define IW_PMKSA_REMOVE                2
#define IW_PMKSA_FLUSH                 3
#endif

#ifndef wireless_nlevent_flush
#define wireless_nlevent_flush() ((void)0)
#endif

struct iw_request_info;
union iwreq_data;
struct net_device;
typedef int (*iw_handler)(struct net_device *dev,
                          struct iw_request_info *info,
                          union iwreq_data *wrqu,
                          char *extra);

/* IW_HANDLER macro stub */
#ifndef IW_HANDLER
#define IW_HANDLER(cmd, func) (func)
#endif

/* Define iw_handler_def struct */
struct iw_handler_def {
    int num_standard;
    iw_handler *standard;
    int (*get_wireless_stats)(struct net_device *dev);
};

#endif /* __WIRELESS_H__ */
