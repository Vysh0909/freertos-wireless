#ifndef __WIRELESS_H__
#define __WIRELESS_H__

/* Auto-generated stub header: wireless.h */

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

#define IW_EVENT_CAPA_SIZE        8
#define IW_EVENT_CAPA_K_0         0
#define IW_EVENT_CAPA_K_1         1

#define IW_EVENT_CAPA_SET_KERNEL(x)  memset(x, 0, sizeof(x))
#define IW_EVENT_CAPA_SET(x, y)      do { } while (0)

#define IW_RETRY_LIFETIME 0x1000
#define IW_RETRY_LIMIT    0x2000
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

#endif /* __WIRELESS_H__ */
