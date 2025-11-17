#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include "../linux/workqueue.h"
typedef unsigned int gfp_t;
typedef unsigned int mode_t;
typedef long long loff_t;
typedef int pid_t;

struct workqueue_struct *system_power_efficient_wq = NULL;
// --- 0. Memory Allocation ---
// kcalloc is the kernel's calloc. It must be implemented to use your heap functions.
void *kcalloc(size_t n, size_t size, gfp_t flags) { panic(); }


// --- 1. Netlink, NLA, and SKB Stubs ---

// NLA Parsing
int nla_parse_nested(void *a, int b, const void *c) { panic(); }
int nla_parse_nested_deprecated(void *a, int b, const void *c, const void *d) { panic(); }
uint8_t nla_get_u8_default(const void *a, uint8_t default_val) { panic(); }

// NLA Getters
uint16_t nla_type(const void *nla) { panic(); }
uint16_t nla_get_u16(const void *nla) { panic(); }
uint8_t nla_get_u8(const void *nla) { panic(); }
int nla_get_flag(const void *nla) { panic(); }
int32_t nla_get_s32(const void *nla) { panic(); }
int8_t nla_get_s8(const void *nla) { panic(); }

// NLA Putter (for generating messages)
int nla_put_u32(void *a, int b, uint32_t c) { panic(); }

// Netlink Message Handling
void *nla_nest_end(void *a, void *b) { panic(); }
void *genlmsg_end(void *a, void *b) { panic(); }
void *nlmsg_hdr(const void *skb) { panic(); }
void *genlmsg_put(void *a, int b, int c, void *d, int e, uint8_t f) { panic(); }

// Netlink Communication
int genlmsg_multicast_netns(void *skb, uint32_t portid, uint32_t group, int flags) { panic(); }
int genlmsg_unicast(void *skb, uint32_t portid) { panic(); }
int genlmsg_reply(void *skb, void *info) { panic(); }

// Freeing of a network buffer (sk_buff)
void kfree_skb(void *skb) { panic(); }


// --- 2. Concurrency and Synchronization Stubs ---

// RCU (Read-Copy-Update) stubs:
void rcu_read_lock(void) { panic(); }
void rcu_read_unlock(void) { panic(); }
void *rcu_dereference(void *p) { panic(); }
void *rcu_dereference_protected(void *p) { panic(); }

// Lockdep stub: 
int lockdep_is_held(void) { panic(); }

// Spinlocks 
void spin_lock_bh(void) { panic(); }
void spin_unlock_bh(void) { panic(); }


// --- 3. Timing Stubs ---
// jiffies is a global variable.
uint64_t jiffies = 0; 


// --- 4. Utility Functions ---

// Safe Integer Utilities
size_t array_size(size_t a, size_t b) { panic(); }
size_t size_add(size_t a, size_t b) { panic(); }

// Linux Kernel Error Handling Helpers
bool IS_ERR(const void *ptr) { panic(); }
long PTR_ERR(const void *ptr) { panic(); }
long PTR_ERR_OR_ZERO(const void *ptr) { panic(); }
void *ERR_PTR(long error) { panic(); }

// Bit Manipulation
int hweight16(uint16_t w) { panic(); }
uint16_t u16_get_bits(uint16_t val, uint16_t mask) { panic(); }

// Compile-time checks (Often resolves to a dummy macro, needs a function here if linked)
void BUILD_BUG_ON(int condition) { panic(); }


// --- 5. Networking Device Stubs ---

// Device Get/Put
void dev_hold(void *dev) { panic(); }
void dev_put(void *dev) { panic(); }
void *dev_get_by_index(void *net, int ifindex) { panic(); } // Added for dev_get_by_index

// MAC Address Helpers
const uint8_t eth_broadcast_data[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
const uint8_t *eth_broadcast_addr = eth_broadcast_data; 
const uint8_t eth_zero_data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const uint8_t *eth_zero_addr = eth_zero_data; // Added for eth_zero_addr

// --- NEW Memory Allocation Helpers ---
void kfree_sensitive(const void *p, size_t size) { panic(); }
void *kmemdup(const void *src, size_t len, gfp_t gfp) { panic(); }

// --- NEW Networking/Netlink Helpers ---
bool is_valid_ether_addr(const uint8_t *addr) { panic(); } // Added for is_valid_ether_addr
void *sock_net(const void *sk) { panic(); } // Added for sock_net
void *genl_info_net(const void *info) { panic(); } // Added for genl_info_net
void GENL_SET_ERR_MSG(const void *info, const char *msg) { panic(); } // Added for GENL_SET_ERR_MSG

// --- NEW Netlink Message Functions ---
int nlmsg_parse_deprecated(const void *nlh, int hdrlen, void *tb, int maxtype, const void *policy) { panic(); }
void nlmsg_free(void *nlh) { panic(); }
int genlmsg_cancel(void *skb, void *head) { panic(); }

// --- NEW NLA Getters and Putters ---
uint64_t nla_get_u64(const void *nla) { panic(); }
int nla_put(void *skb, int attrtype, int attrlen, const void *data) { panic(); }
int nla_put_u64_64bit(void *skb, int attrtype, uint64_t value, int padattr) { panic(); }


// --- NEW RCU Synchronization ---
void rcu_assign_pointer(void *p, void *v) { panic(); }


// --- Final Netlink/Networking Stubs ---

// Net namespace (Net-ns) functions
void put_net(void *net) { panic(); }
void *get_net_ns_by_fd(int fd) { panic(); }

// Netlink message helpers
void *nlmsg_data(const void *nlh) { panic(); }
int nlmsg_len(const void *nlh) { panic(); }

// General Netlink/Dump helpers
void genl_dump_check_consistent(void *cb, void *user_dump) { panic(); }

// Netlink Attribute (NLA) Getters/Putters
uint16_t nla_get_u16_default(const void *a, uint16_t default_val) { panic(); }
uint32_t nla_get_u32_default(const void *a, uint32_t default_val) { panic(); }
int nla_put_string(void *skb, int attrtype, const char *str) { panic(); }
int nla_put_u8(void *skb, int attrtype, uint8_t value) { panic(); }
int nla_validate_nested(const void *a, int b, const void *c) { panic(); }
void nla_memcpy(void *dest, const void *nla, size_t count) { panic(); }
void *nla_find_nested(const void *a, int b, int c) { panic(); }

// Net Device helpers
void *__dev_get_by_index(void *net, int ifindex) { panic(); }
bool netif_is_bridge_port(const void *dev) { panic(); }

// Kernel Memory
void *kmalloc(size_t size, gfp_t flags) { panic(); }

// Byte Order
uint16_t cpu_to_be16(uint16_t val) { panic(); }

// List/Containers
void list_add(void *new, void *head) { panic(); }

// Utility/Array checks
unsigned int array_index_nospec(unsigned int index, unsigned int limit) { panic(); }

// Macro/Function stubs (often macros in kernel, must be functions here)
void NL_SET_BAD_ATTR(void *skb, void *attr) { panic(); }


// --- NEW DebugFS Stubs (from debugfs.o) ---
void *debugfs_create_file(const char *name, mode_t mode, void *parent, void *data, const void *fops) { panic(); }
void debugfs_enter_cancellation(void) { panic(); }
void debugfs_leave_cancellation(void) { panic(); }
int simple_read_from_buffer(void *to, size_t len, loff_t *ppos, const void *from, size_t avail) { panic(); }


// --- NEW User Space Copy & Sync Stubs ---
unsigned long copy_from_user(void *to, const void *from, unsigned long n) { panic(); }
long wait_for_completion(void *x) { panic(); }


// --- NEW Wireless Extensions (WEXT) Stubs ---
void *cfg80211_ibss_wext_giwessid(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_siwessid(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_giwap(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_siwap(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_giwfreq(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_join(void *dev, void *info) { panic(); }
void *cfg80211_ibss_wext_siwfreq(void *dev, void *info) { panic(); }
void *cfg80211_wext_siwscan(void *dev, void *info) { panic(); }
void *cfg80211_wext_giwscan(void *dev, void *info) { panic(); }


// --- NEW RFKill Stubs ---
int rfkill_set_sw_state(void *rfkill, bool blocked) { panic(); }


// --- NEW MAC Address Helpers ---
bool is_broadcast_ether_addr(const uint8_t *addr) { panic(); }
bool ether_addr_equal(const uint8_t *addr1, const uint8_t *addr2) { panic(); }
void ether_addr_copy(uint8_t *dst, const uint8_t *src) { panic(); }


// --- NEW Netlink/Networking/Utility Stubs ---
void *get_net_ns_by_pid(pid_t pid) { panic(); }
void *nl_set_extack_cookie_u64(void *extack, uint64_t cookie) { panic(); }
void *nla_memdup(const void *nla, gfp_t flags) { panic(); }
int hweight32(uint32_t w) { panic(); }
void flush_delayed_work(void *work) { panic(); }
int nla_get_s16(const void *nla) { panic(); }


// --- NEW String/Buffer Stubs (from ethtool.o, debugfs.o) ---
size_t strscpy(char *dest, const char *src, size_t count) { panic(); }
int scnprintf(char *buf, size_t size, const char *fmt, ...) { panic(); } // Variable args, requires special handling, but panic() simplifies it.

// --- NEW Memory Stubs (from pmsr.o) ---
void *kzalloc(size_t size, gfp_t flags) { panic(); }

// --- NEW Netlink/Tracing Stubs (from pmsr.o) ---
void *nla_find(const void *head, int remaining, int attrtype) { panic(); }
void trace_cfg80211_pmsr_complete(void *wiphy, void *req, void *res, int err) { panic(); }

// --- NEW POSIX Threads (Pthreads) Stubs (from debugfs.o) ---
// Note: These must be stubbed as the compiled object depends on them.
int pthread_mutex_lock(void *mutex) { panic(); }
int pthread_mutex_unlock(void *mutex) { panic(); }
int pthread_cond_signal(void *cond) { panic(); }

// --- NEW Work Queue/Timer Stubs (from mlme.o) ---
// Note: You must ensure you've defined 'to_delayed_work' and 'delayed_work_pending' correctly if they were missed.
// Also, 'struct delayed_work' is likely needed for the argument types, but we'll use void* for panic stubs.
int cancel_delayed_work(void *dwork) { panic(); }
bool queue_delayed_work(void *wq, void *dwork, unsigned long delay) { panic(); }
void *to_delayed_work(void *work) { panic(); }
bool delayed_work_pending(void *dwork) { panic(); }
// Already added in previous step: void flush_delayed_work(void *work) { panic(); }


// --- NEW Timing/Jiffies Stubs (from mlme.o) ---
unsigned long msecs_to_jiffies(const unsigned int m) { panic(); }

// Time comparison macro/function: time_after_eq(a, b) is often just ((long)(a) - (long)(b) >= 0)
// Must be implemented as a function stub here.
int time_after_eq(unsigned long a, unsigned long b) { panic(); }

// --- NEW Bit/Byte Order/Utility Stubs (from chan.o) ---
uint16_t __le16_to_cpu(uint16_t val) { panic(); } // Byte order conversion
uint32_t u32_get_bits(uint32_t val, uint32_t mask) { panic(); } // Bit manipulation

// Common utilities (often macros, but linked as functions)
long max(long x, long y) { panic(); }
void swap(void *a, void *b, size_t size) { panic(); }

// Bitfield lookup
unsigned long find_first_bit(const unsigned long *addr, unsigned long size) { panic(); }
unsigned long find_next_bit(const unsigned long *addr, unsigned long size, unsigned long offset) { panic(); }

// --- NEW Tracing Stubs (from chan.o) ---
void trace_cfg80211_reg_can_beacon(void *wiphy, void *chan, int err) { panic(); }

// --- NEW RCU (Read-Copy-Update) Stubs (from reg.o) ---
// RCU is a complex synchronization primitive. We stub it out here.
void *rcu_dereference_rtnl(const void *p) { panic(); }
void *rcu_dereference_check(const void *p, int c) { panic(); }


// --- NEW Work Queue Stubs (from reg.o) ---
bool mod_delayed_work(void *wq, void *dwork, unsigned long delay) { panic(); }


// --- NEW Kernel Message/Diagnostic Stubs (from reg.o, scan.o) ---
void pr_debug(const char *fmt, ...) { panic(); } // Variable args, requires special handling, but panic() simplifies it.
void WARN(int condition, const char *fmt, ...) { panic(); } // Same, often a macro that expands to a function call.
void lockdep_rtnl_is_held(void) { panic(); } // Lock debugging, stubbing should be fine.
void WARN_ONCE(int condition, const char *fmt, ...) { panic(); }
void net_dbg_ratelimited(const char *fmt, ...) { panic(); }


// --- NEW Platform/Device Stubs (from reg.o) ---
void *platform_device_register_simple(const char *name, int id, void *pdata, unsigned int size) { panic(); }
void dev_set_uevent_suppress(void *dev, int val) { panic(); }
void platform_device_unregister(void *pdev) { panic(); }

// IS_ERR_OR_NULL is often a macro, but linking as a function here.
bool IS_ERR_OR_NULL(const void *ptr) { panic(); }


// --- NEW Atomic Operation Stubs (from scan.o) ---
int atomic_read(const void *v) { panic(); }


// --- NEW Red-Black Tree (RB-Tree) Stubs (from scan.o) ---
void rb_link_node(void *node, void *parent, void *rb_node) { panic(); }
void rb_insert_color(void *node, void *root) { panic(); }
void rb_erase(void *node, void *root) { panic(); }


// --- NEW CRC/Bit/Byte Encoding Stubs (from scan.o) ---
uint8_t u8_encode_bits(uint8_t val, uint8_t mask) { panic(); }
uint32_t crc32_le(uint32_t crc, const uint8_t *p, size_t len) { panic(); }
uint16_t le16_encode_bits(uint16_t val, uint16_t mask) { panic(); }
uint64_t get_unaligned_le64(const void *p) { panic(); }
uint64_t le64_to_cpu(uint64_t val) { panic(); }


// --- NEW sk_buff (Socket Buffer) Helpers (from util.o) ---
void skb_add_rx_frag(void *skb, int i, void *page, int offset, int size, unsigned int truesize) { panic(); }
unsigned int skb_frag_size(const void *frag) { panic(); }
void *skb_frag_page(const void *frag) { panic(); }
void *skb_frag_address(const void *frag) { panic(); }
void *skb_shinfo(const void *skb) { panic(); }
void *get_page(void *page) { panic(); }
void *page_address(const void *page) { panic(); }
void __skb_queue_purge(void *list) { panic(); }
void dev_kfree_skb(void *skb) { panic(); }
void *skb_pull(void *skb, unsigned int len) { panic(); }
bool skb_has_frag_list(const void *skb) { panic(); }
bool skb_vlan_tag_present(const void *skb) { panic(); }
uint16_t skb_vlan_tag_get(const void *skb) { panic(); }
void *skb_header_pointer(const void *skb, int offset, int len, void *buf) { panic(); }
void *skb_put(void *skb, unsigned int len) { panic(); }
void *dev_alloc_skb(unsigned int length) { panic(); }

// --- NEW Networking/IP Stubs (from util.o) ---
void *ipv6_hdr(const void *skb) { panic(); }
uint8_t ipv6_get_dsfield(const void *hdr) { panic(); }
void *ip_hdr(const void *skb) { panic(); }
uint8_t ipv4_get_dsfield(const void *hdr) { panic(); }
void netdev_err(const void *dev, const char *fmt, ...) { panic(); }
uint16_t eth_type_trans(void *skb, void *dev) { panic(); }
int netif_rx(void *skb) { panic(); }

// --- NEW Utility/Math Stubs (from util.o) ---
// do_div is a GCC built-in or macro, linking as a function here.
uint32_t do_div(uint64_t *n, uint32_t base) { panic(); }
void *kmemdup_array(const void *src, size_t n, size_t size, gfp_t flags) { panic(); }
unsigned long gcd(unsigned long a, unsigned long b) { panic(); }
// ALIGN is typically a macro, but linking as a function here.
unsigned long ALIGN(unsigned long x, unsigned long mask) { panic(); }

// --- NEW Firmware/Regulatory Stubs (from reg.o) ---
int request_firmware(const void **fw, const char *name, void *device) { panic(); }
void release_firmware(const void *fw) { panic(); }
int request_firmware_nowait(void *a, int b, const char *c, void *d, gfp_t e, void *f, void *g) { panic(); }

// --- NEW Locking/List/Logging Stubs (from reg.o) ---
spinlock_t reg_pending_beacons_lock = { 0 };
void list_splice_tail_init(void *list, void *head) { panic(); }
void pr_info(const char *fmt, ...) { panic(); } // General info logging

// --- NEW Byte Order Stubs (from reg.o) ---
uint32_t be32_to_cpu(uint32_t val) { panic(); }


// --- NEW SysFS/Device Model Stubs (from sysfs.o) ---
void *class_register(const void *cls) { panic(); }
void class_unregister(void *cls) { panic(); }


// --- NEW sk_buff/Networking Stubs (from util.o) ---
bool pskb_may_pull(void *skb, unsigned int len) { panic(); }
void *pskb_pull(void *skb, unsigned int len) { panic(); }
void skb_postpull_rcsum(void *skb, const void *hdr, int len) { panic(); }
void *skb_push(void *skb, unsigned int len) { panic(); }
void skb_reset_network_header(void *skb) { panic(); }
void __skb_queue_tail(void *list, void *newsk) { panic(); }
void skb_reserve(void *skb, int len) { panic(); }

bool likely(long x) { return x; } // Implementing it to return the condition is technically safer than panic, as it is a prediction.

void *virt_to_head_page(const void *kaddr) { panic(); }




/*--------------------------mac80211-------------------------*/

uint16_t be16_to_cpup(const uint16_t *p) { panic(); }
uint32_t be32_to_cpup(const uint32_t *p) { panic(); }
void put_unaligned(const void *src, void *dst) { panic(); }
int pskb_trim(void *skb, unsigned int len) { panic(); }
int skb_linearize(void *skb) { panic(); }
unsigned int skb_queue_len(const void *list) { panic(); }
void *skb_peek(const void *list) { panic(); }
unsigned int skb_tailroom(const void *skb) { panic(); }
int skb_trim(void *skb, unsigned int len) { panic(); }
long atomic64_inc_return(long *v) { panic(); }
int crypto_memneq(const void *a, const void *b, size_t size) { panic(); }
int acpi_amd_wbrf_supported_producer(void) { panic(); }

void skb_put_data(void *skb, const void *data, unsigned int len) { panic(); }
void skb_put_u8(void *skb, unsigned char value) { panic(); }

void *alloc_skb(unsigned long size, int flags) { panic(); }
void consume_skb(void *skb) { panic(); }

int test_bit(long bit, const unsigned long *addr) { panic(); }

int WARN_ON_ONCE(int condition) { panic(); }

void pr_warn_ratelimited(const char *fmt, ...) { panic(); }

void arc4_setkey(void *ctx, const unsigned char *key, unsigned int keylen) { panic(); }
void arc4_crypt(void *ctx, const unsigned char *in, unsigned char *out, unsigned int len) { panic(); }

void memzero_explicit(void *s, unsigned long count) { panic(); }

unsigned int skb_headroom(const void *skb) { panic(); }

unsigned int skb_get_hash(const void *skb) { panic(); }

void put_unaligned_be16(unsigned short val, void *p) { panic(); }

void local_bh_enable(void) { panic(); }
void flush_workqueue(void *wq) { panic(); }
void barrier(void) { panic(); }

void trace_drv_set_frag_threshold(void) { panic(); }
void trace_drv_return_int(void) { panic(); }
void trace_drv_set_rts_threshold(void) { panic(); }
void trace_drv_set_coverage_class(void) { panic(); }
void trace_drv_reconfig_complete(void) { panic(); }
void trace_drv_return_void(void) { panic(); }

void ewma_beacon_signal_read(void) { panic(); }
void trace_api_radar_detected(void) { panic(); }

void u32_encode_bits(void) { panic(); }

void skb_put_zero(void *skb, unsigned int len) { panic(); }

void put_unaligned_le16(void *p, unsigned short v) { panic(); }

void *netdev_priv(const void *dev) { panic(); }

void GENMASK(void) { panic(); }
void FIELD_MAX(void) { panic(); }
void FIELD_PREP(void) { panic(); }

void __skb_queue_head_init(void *list) { panic(); }
void *skb_clone(const void *skb, int gfp) { panic(); }
void skb_ensure_writable(void *skb, unsigned int len) { panic(); }
void *__skb_dequeue(void *list) { panic(); }
void *skb_copy(const void *skb, int gfp) { panic(); }
void skb_set_queue_mapping(void *skb, int q) { panic(); }
void *skb_share_check(void *skb, int gfp) { panic(); }
void *skb_dequeue(void *list) { panic(); }
int skb_queue_empty(const void *list) { panic(); }
void skb_reset_mac_header(void *skb) { panic(); }

void sk_pacing_shift_update(void *sk, int val) { panic(); }

void clear_bit(int nr, void *addr) { panic(); }
void set_bit(int nr, void *addr) { panic(); }
int test_and_clear_bit(int nr, void *addr) { panic(); }
void __clear_bit(int nr, void *addr) { panic(); }

void FIELD_FIT(void) { panic(); }

void local_bh_disable(void) { panic(); }
void trace_stop_queue(void) { panic(); }
void trace_wake_queue(void) { panic(); }
void trace_drv_flush(void) { panic(); }
void trace_drv_wake_tx_queue(void) { panic(); }
void pr_warn(const char *fmt, ...) { panic(); }

void dev_sw_netstats_tx_add(void *dev, void *stats, unsigned int len) { panic(); }

void skb_queue_tail(void *list, void *skb) { panic(); }
int skb_get_queue_mapping(const void *skb) { panic(); }
void *fq_tin_filter(void *tin, void *skb) { panic(); }
void fq_tin_init(void *tin) { panic(); }
void codel_vars_init(void *vars) { panic(); }
void codel_stats_init(void *stats) { panic(); }
void fq_tin_reset(void *tin) { panic(); }
void fq_init(void *fq) { panic(); }
void codel_params_init(void *params) { panic(); }
void MS2TIME(void) { panic(); }
void *kvcalloc(size_t n, size_t size, int flags) { panic(); }
void fq_reset(void *fq) { panic(); }
void kvfree(void *ptr) { panic(); }
int time_before_eq(unsigned long a, unsigned long b) { panic(); }
void *fq_flow_idx(void *fq, void *skb) { panic(); }
unsigned long codel_get_time(void) { panic(); }
void fq_tin_enqueue(void *tin, void *flow, void *skb, unsigned int qlen) { panic(); }
int skb_is_gso(const void *skb) { panic(); }
void *fq_flow_classify(void *fq, void *skb) { panic(); }
void *skb_peek_tail(const void *list) { panic(); }
int pskb_expand_head(void *skb, int add_head, int add_tail, int gfp) { panic(); }
void dev_printk(const char *level, const void *dev, const char *fmt, ...) { panic(); }
void skb_mark_not_on_list(void *skb) { panic(); }
void skb_queue_head(void *list, void *skb) { panic(); }

int is_unicast_ether_addr(const unsigned char *addr) { panic(); }

void skb_set_mac_header(void *skb, int offset) { panic(); }
void skb_set_network_header(void *skb, int offset) { panic(); }
void skb_set_transport_header(void *skb, int offset) { panic(); }

int static_branch_unlikely(const void *key) { panic(); }

unsigned int softirq_count(void) { panic(); }

void *fq_tin_dequeue(void *tin, void *cvars, unsigned int *packets, unsigned int *bytes) { panic(); }

void skb_queue_splice_tail(void *list, void *head) { panic(); }

void list_move_tail(void *item, void *list) { panic(); }

void kfree_skb_list(void *skb_list) { panic(); }

void kcov_remote_start_common(void) { panic(); }
void kcov_remote_stop(void) { panic(); }

void dev_sw_netstats_rx_add(void *dev, void *stats, unsigned int len) { panic(); }

void netif_receive_skb(void *skb) { panic(); }
void netif_receive_skb_list(void *list) { panic(); }

int skb_mac_header_was_set(const void *skb) { panic(); }

void *netdev_alloc_skb(void *dev, unsigned int len) { panic(); }

int ilog2(unsigned long x) { panic(); }

void dev_kfree_skb_any(void *skb) { panic(); }

void trace_drv_mgd_protect_tdls_discover(void) { panic(); }
void trace_drv_tdls_channel_switch(void) { panic(); }
void trace_drv_tdls_cancel_channel_switch(void) { panic(); }
void trace_drv_tdls_recv_channel_switch(void) { panic(); }
void trace_drv_update_tkip_key(void) { panic(); }

unsigned short swab16(unsigned short x) { panic(); }
unsigned short ror16(unsigned short x, unsigned int shift) { panic(); }

void put_unaligned_le32(unsigned int val, void *p) { panic(); }

int skb_cloned(const void *skb) { panic(); }
int skb_clone_writable(const void *skb, unsigned int len) { panic(); }

void *codel_dequeue(void *cvars, unsigned int *len, unsigned int *dropped) { panic(); }
void *fq_flow_dequeue(void *flow) { panic(); }

void *skb_gso_segment(void *skb, int features) { panic(); }
int skb_needs_linearize(const void *skb) { panic(); }
int __skb_linearize(void *skb) { panic(); }

int skb_checksum_start_offset(const void *skb) { panic(); }
void skb_set_inner_transport_header(void *skb, int offset) { panic(); }
void skb_csum_hwoffload_help(void *skb) { panic(); }

void *skb_clone_sk(void *skb) { panic(); }

int idr_alloc(void *idr, void *ptr, int start, int end, int gfp) { panic(); }

int bitmap_empty(const unsigned long *bitmap, unsigned int nbits) { panic(); }

void skb_copy_queue_mapping(void *to, const void *from) { panic(); }

void ewma_avg_signal_add(void) { panic(); }
void ktime_set(void) { panic(); }
void skb_copy_expand(void) { panic(); }
void skb_cow_head(void) { panic(); }

void u64_stats_update_begin(void) { panic(); }
void u64_stats_update_end(void) { panic(); }

void dev_queue_xmit(void) { panic(); }
void skb_headlen(void) { panic(); }
void skb_set_tail_pointer(void) { panic(); }

void net_info_ratelimited(void) { panic(); }

void put_unaligned_le64(void) { panic(); }

void __pskb_trim(void) { panic(); }

void ewma_signal_add(void) { panic(); }

void this_cpu_ptr(void) { panic(); }

void kfree_skb_reason(void) { panic(); }

void trace_drv_sta_notify(void) { panic(); }
void trace_drv_event_callback(void) { panic(); }
void trace_drv_sta_set_decap_offload(void) { panic(); }

void time_after(void) { panic(); }

void skb_queue_head_init(void) { panic(); }

void test_and_set_bit(void) { panic(); }

void led_trigger_blink_oneshot(void) { panic(); }

void __skb_peek(void) { panic(); }

void ktime_to_ns(void) { panic(); }

void net_ratelimit(void) { panic(); }

void skb_get_kcov_handle(void) { panic(); }

void free_percpu(void) { panic(); }
void smp_mb(void) { panic(); }

void rhltable_insert(void) { panic(); }
void rhltable_remove(void) { panic(); }
void rhltable_init(void) { panic(); }
void rhltable_destroy(void) { panic(); }
void rhltable_lookup(void) { panic(); }

void list_add_tail_rcu(void) { panic(); }

void skb_queue_splice_tail_init(void) { panic(); }

void trace_api_sta_block_awake(void) { panic(); }
void trace_api_eosp(void) { panic(); }
void trace_api_send_eosp_nullfunc(void) { panic(); }
void trace_api_sta_set_buffered(void) { panic(); }
void trace_drv_get_expected_throughput(void) { panic(); }
void trace_drv_return_u32(void) { panic(); }
void trace_drv_sta_statistics(void) { panic(); }

void atomic_sub_return(void) { panic(); }
void atomic_sub(void) { panic(); }
void atomic_add(void) { panic(); }
void atomic_cmpxchg(void) { panic(); }

void per_cpu_ptr(void) { panic(); }

void ktime_get_seconds(void) { panic(); }

void ewma_signal_read(void) { panic(); }
void ewma_avg_signal_read(void) { panic(); }

void u64_stats_fetch_begin(void) { panic(); }
void u64_stats_fetch_retry(void) { panic(); }

void idr_remove(void) { panic(); }

void skb_complete_wifi_ack(void) { panic(); }
void skb_is_nonlinear(void) { panic(); }
void skb_network_offset(void) { panic(); }
void skb_network_header(void) { panic(); }

void get_unaligned_be16(void) { panic(); }

void skb_orphan(void) { panic(); }

void round_jiffies_relative(void) { panic(); }

void trace_drv_cancel_hw_scan(void) { panic(); }
void trace_drv_sched_scan_start(void) { panic(); }
void trace_drv_sched_scan_stop(void) { panic(); }
void trace_api_sched_scan_results(void) { panic(); }
void trace_api_sched_scan_stopped(void) { panic(); }

void le32_encode_bits(void) { panic(); }

void trace_drv_allow_buffered_frames(void) { panic(); }
void trace_drv_flush_sta(void) { panic(); }
void trace_drv_set_tim(void) { panic(); }
void trace_drv_release_buffered_frames(void) { panic(); }
void trace_drv_sync_rx_queues(void) { panic(); }
void trace_drv_sta_pre_rcu_remove(void) { panic(); }

void u64_stats_init(void) { panic(); }
void ewma_signal_init(void) { panic(); }
void ewma_avg_signal_init(void) { panic(); }

void ktime_get_boottime_ns(void) { panic(); }

void atomic_set(void) { panic(); }

void eth_random_addr(void) { panic(); }

void netif_carrier_on(void) { panic(); }
void netif_carrier_off(void) { panic(); }

void skb_queue_purge(void) { panic(); }

void trace_drv_remain_on_channel(void) { panic(); }
void trace_api_ready_on_channel(void) { panic(); }
void trace_api_remain_on_channel_expired(void) { panic(); }

void bitmap_zero(void) { panic(); }
void __set_bit(void) { panic(); }

void crc32_be(void) { panic(); }

void mb(void) { panic(); }

void drv_suspend(void) { panic(); }

void cfg80211_report_wowlan_wakeup(void) { panic(); }

void trace_drv_sta_rate_tbl_update(void) { panic(); }

void kernel_param_lock(void) { panic(); }
void kernel_param_unlock(void) { panic(); }

void dev_warn(void) { panic(); }

void debugfs_create_u32(void) { panic(); }

void time_is_after_jiffies(void) { panic(); }

void DIV_ROUND_CLOSEST(void) { panic(); }

void nonseekable_open(void) { panic(); }

void trace_drv_twt_teardown_request(void) { panic(); }
void trace_drv_add_twt_setup(void) { panic(); }

void trace_drv_sw_scan_complete(void) { panic(); }
void trace_drv_hw_scan(void) { panic(); }
void get_random_u16(void) { panic(); }
void trace_drv_sw_scan_start(void) { panic(); }

void trace_api_scan_completed(void) { panic(); }

void bitmap_subset(void) { panic(); }
void round_jiffies_up(void) { panic(); }
void trace_drv_mgd_prepare_tx(void) { panic(); }
void netdev_info(void) { panic(); }
void trace_api_chswitch_done(void) { panic(); }
void trace_api_cqm_beacon_loss_notify(void) { panic(); }
void trace_drv_mgd_complete_tx(void) { panic(); }
void trace_drv_sta_set_4addr(void) { panic(); }
void ewma_beacon_signal_add(void) { panic(); }
void trace_api_cqm_rssi_notify(void) { panic(); }
void unlikely(void) { panic(); }
void ewma_beacon_signal_init(void) { panic(); }
void usecs_to_jiffies(void) { panic(); }
void trace_drv_tx_frames_pending(void) { panic(); }
void trace_drv_return_bool(void) { panic(); }
void trace_api_beacon_loss(void) { panic(); }
void trace_api_disconnect(void) { panic(); }
void trace_drv_can_neg_ttlm(void) { panic(); }
void trace_drv_neg_ttlm_res(void) { panic(); }
void u16_encode_bits(void) { panic(); }

void skb_checksum_help(void) { panic(); }
void BITMAP_FROM_U64(void) { panic(); }
void INIT_HLIST_HEAD(void) { panic(); }
void kmem_cache_create(void) { panic(); }
int time_before(unsigned long a, unsigned long b) { panic(); }
int printk_ratelimit(void) { panic(); }
void ewma_mesh_fail_avg_add(void) { panic(); }
int ewma_mesh_fail_avg_read(void) { panic(); }



void rhashtable_lookup_get_insert_fast(void) { panic(); }
void rhashtable_lookup_insert_fast(void) { panic(); }
void rhashtable_init(void) { panic(); }
void rhashtable_free_and_destroy(void) { panic(); }

void hlist_add_head(void) { panic(); }
void hlist_add_head_rcu(void) { panic(); }
void hlist_del_rcu(void) { panic(); }

void timer_shutdown_sync(void) { panic(); }

void bitmap_zalloc(void) { panic(); }
void find_first_zero_bit(void) { panic(); }
void bitmap_free(void) { panic(); }
void bitmap_copy(void) { panic(); }

void rcu_read_lock_held(void) { panic(); }

void rol32(void) { panic(); }
void ror32(void) { panic(); }

void KUNIT_STATIC_STUB_REDIRECT(void) { panic(); }
void trace_api_connection_loss(void) { panic(); }
void trace_drv_abort_channel_switch(void) { panic(); }
void trace_drv_post_channel_switch(void) { panic(); }
void trace_drv_channel_switch_rx_beacon(void) { panic(); }
void trace_drv_pre_channel_switch(void) { panic(); }
void trace_drv_channel_switch(void) { panic(); }
void trace_api_enable_rssi_reports(void) { panic(); }


void kasprintf(void) { panic(); }
void led_trigger_blink(void) { panic(); }

void trace_drv_can_activate_links(void) { panic(); }

void trace_drv_config(void) { panic(); }
void trace_drv_prepare_multicast(void) { panic(); }
void trace_drv_return_u64(void) { panic(); }
void trace_drv_configure_filter(void) { panic(); }
void trace_drv_link_info_changed(void) { panic(); }
void trace_drv_vif_cfg_changed(void) { panic(); }
void trace_api_restart_hw(void) { panic(); }
void dev_info(void) { panic(); }
void __hw_addr_init(void) { panic(); }
void idr_init(void) { panic(); }
void tasklet_setup(void) { panic(); }
void idr_for_each(void) { panic(); }
void idr_destroy(void) { panic(); }

void kmem_cache_destroy(void) { panic(); }
void kmem_cache_alloc(void) { panic(); }
void __dev_alloc_skb(void) { panic(); }
void __le32_to_cpu(void) { panic(); }

void skb_reset_transport_header(void) { panic(); }
void ewma_mesh_tx_rate_avg_add(void) { panic(); }
void ewma_mesh_tx_rate_avg_read(void) { panic(); }
void mult_frac(void) { panic(); }
void ewma_mesh_fail_avg_init(void) { panic(); }

void __get_unaligned_cpu32(void) { panic(); }
void jhash_1word(void) { panic(); }
void rhashtable_replace_fast(void) { panic(); }
void atomic_add_unless(void) { panic(); }


void crypto_skcipher_encrypt(void) { panic(); }
void skcipher_request_free(void) { panic(); }
void crypto_alloc_skcipher(void) { panic(); }
void crypto_skcipher_setkey(void) { panic(); }
void skcipher_request_alloc(void) { panic(); }
void sg_init_one(void) { panic(); }
void skcipher_request_set_crypt(void) { panic(); }
void crypto_skcipher_decrypt(void) { panic(); }
void crypto_free_skcipher(void) { panic(); }
void crypto_alloc_shash(void) { panic(); }
void crypto_shash_setkey(void) { panic(); }
void crypto_free_shash(void) { panic(); }

void trace_api_prepare_rx_omi_bw(void) { panic(); }
void trace_api_return_bool(void) { panic(); }
void trace_api_finalize_rx_omi_bw(void) { panic(); }
void trace_api_return_void(void) { panic(); }

void trace_api_request_smps(void) { panic(); }

void trace_drv_join_ibss(void) { panic(); }
void trace_drv_leave_ibss(void) { panic(); }
void trace_drv_tx_last_beacon(void) { panic(); }

void trace_drv_net_setup_tc(void) { panic(); }
void eth_mac_addr(void) { panic(); }
void netif_carrier_ok(void) { panic(); }
void __hw_addr_sync(void) { panic(); }
void trace_drv_net_fill_forward_path(void) { panic(); }
void ether_setup(void) { panic(); }
void __ffs64(void) { panic(); }
void hweight64(void) { panic(); }
void fls64(void) { panic(); }
void netif_addr_lock_bh(void) { panic(); }
void __hw_addr_unsync(void) { panic(); }
void netif_addr_unlock_bh(void) { panic(); }
void trace_drv_config_iface_filter(void) { panic(); }
void netdev_set_default_ethtool_ops(void) { panic(); }
void free_netdev(void) { panic(); }
void alloc_netdev_mqs(void) { panic(); }
void dev_net_set(void) { panic(); }
void dev_alloc_name(void) { panic(); }
void eth_hw_addr_set(void) { panic(); }
void SET_NETDEV_DEV(void) { panic(); }
void list_splice_init(void) { panic(); }


void trace_drv_set_default_unicast_key(void) { panic(); }
void trace_api_gtk_rekey_notify(void) { panic(); }
void ERR_CAST(void) { panic(); }



void va_start(void) { panic(); }
void va_end(void) { panic(); }
void vscnprintf(void) { panic(); }

void kstrtou64_from_user(void) { panic(); }
void kstrtoul(void) { panic(); }
void atomic64_set(void) { panic(); }
void atomic64_read(void) { panic(); }

void debugfs_create_symlink(void) { panic(); }
void debugfs_create_ulong(void) { panic(); }
void debugfs_create_xul(void) { panic(); }

void trace_drv_start(void) { panic(); }
void trace_drv_stop(void) { panic(); }
void trace_drv_add_interface(void) { panic(); }
void trace_drv_change_interface(void) { panic(); }
void trace_drv_remove_interface(void) { panic(); }
void trace_drv_sta_state(void) { panic(); }
void trace_drv_sta_add(void) { panic(); }
void trace_drv_sta_remove(void) { panic(); }
void trace_drv_sta_set_txpwr(void) { panic(); }
void trace_drv_link_sta_rc_update(void) { panic(); }
void trace_drv_conf_tx(void) { panic(); }
void trace_drv_get_tsf(void) { panic(); }
void trace_drv_set_tsf(void) { panic(); }
void trace_drv_offset_tsf(void) { panic(); }
void trace_drv_reset_tsf(void) { panic(); }
void trace_drv_assign_vif_chanctx(void) { panic(); }
void trace_drv_unassign_vif_chanctx(void) { panic(); }
void trace_drv_switch_vif_chanctx(void) { panic(); }
void trace_drv_ampdu_action(void) { panic(); }
void trace_drv_set_key(void) { panic(); }
void trace_drv_change_vif_links(void) { panic(); }
void trace_drv_change_sta_links(void) { panic(); }
void trace_drv_get_et_sset_count(void) { panic(); }
void trace_drv_get_et_strings(void) { panic(); }
void trace_drv_set_ringparam(void) { panic(); }
void trace_drv_get_ringparam(void) { panic(); }
void trace_drv_get_survey(void) { panic(); }
void trace_drv_get_et_stats(void) { panic(); }

void get_unaligned_be64(void) { panic(); }
void put_unaligned_be64(void) { panic(); }
void crypto_shash_descsize(void) { panic(); }
void crypto_shash_digest(void) { panic(); }
void crypto_xor(void) { panic(); }
void crypto_shash_init(void) { panic(); }
void crypto_shash_update(void) { panic(); }
void crypto_shash_finup(void) { panic(); }

void cpu_to_le64(void) { panic(); }

void tasklet_disable(void) { panic(); }
void tasklet_enable(void) { panic(); }

void codel_time_to_us(void) { panic(); }



void crypto_aead_authsize(void) { panic(); }
void crypto_aead_reqsize(void) { panic(); }
void crypto_aead_encrypt(void) { panic(); }
void crypto_aead_decrypt(void) { panic(); }
void crypto_alloc_aead(void) { panic(); }
void crypto_aead_setkey(void) { panic(); }
void crypto_aead_setauthsize(void) { panic(); }
void crypto_free_aead(void) { panic(); }

void sg_init_table(void) { panic(); }
void sg_set_buf(void) { panic(); }

void call_rcu(void) { panic(); }

void trace_api_start_tx_ba_session(void) { panic(); }
void trace_api_start_tx_ba_cb(void) { panic(); }
void trace_api_stop_tx_ba_session(void) { panic(); }
void trace_api_stop_tx_ba_cb(void) { panic(); }
void trace_drv_add_chanctx(void) { panic(); }
void trace_drv_remove_chanctx(void) { panic(); }
void trace_drv_change_chanctx(void) { panic(); }
void trace_drv_nan_change_conf(void) { panic(); }
void trace_drv_add_nan_func(void) { panic(); }
void trace_drv_stop_nan(void) { panic(); }
void trace_drv_start_nan(void) { panic(); }
void trace_drv_abort_pmsr(void) { panic(); }
void trace_drv_start_pmsr(void) { panic(); }
void trace_drv_get_ftm_responder_stats(void) { panic(); }
void trace_drv_set_rekey_data(void) { panic(); }
void trace_drv_get_antenna(void) { panic(); }
void trace_drv_set_antenna(void) { panic(); }
void trace_drv_get_txpower(void) { panic(); }
void trace_drv_prep_add_interface(void) { panic(); }
void trace_drv_set_bitrate_mask(void) { panic(); }
void trace_drv_get_key_seq(void) { panic(); }
void trace_drv_start_ap(void) { panic(); }
void trace_drv_stop_ap(void) { panic(); }
void trace_drv_channel_switch_beacon(void) { panic(); }
void trace_drv_get_stats(void) { panic(); }

void idr_find(void) { panic(); }

void list_move(void) { panic(); }

void __roundup_pow_of_two(void) { panic(); }
void kstrtou16(void) { panic(); }
void static_branch_inc(void) { panic(); }
void ewma_mesh_tx_rate_avg_init(void) { panic(); }

void aead_request_set_tfm(void) { panic(); }
void aead_request_set_crypt(void) { panic(); }
void aead_request_set_ad(void) { panic(); }
