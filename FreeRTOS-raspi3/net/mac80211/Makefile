# --- Compiler and flags ---
CC := aarch64-none-elf-gcc
CFLAGS := -Wall -O2 -ffreestanding -mcpu=cortex-a53 -I -Itests -I../../porting

# --- Source files ---
SRC := \
        aead_api.c \
        aes_cmac.c \
        aes_gmac.c \
        airtime.c \
        agg-rx.c \
        agg-tx.c \
        chan.c \
        cfg.c \
        debugfs.c \
        debugfs_key.c \
        debugfs_netdev.c \
        debugfs_sta.c \
        driver-ops.c \
        eht.c \
        ethtool.c \
        fils_aead.c \
        he.c \
        ht.c \
        ibss.c \
        iface.c \
        key.c \
        led.c \
        link.c \
        main.c \
        mesh.c \
        mesh_hwmp.c \
        mesh_pathtbl.c \
        mesh_plink.c \
        mesh_ps.c \
        mesh_sync.c \
        michael.c \
        ocb.c \
        offchannel.c \
        parse.c \
        pm.c \
        rate.c \
        rc80211_minstrel_ht.c \
        rc80211_minstrel_ht_debugfs.c \
        rx.c \
        s1g.c \
        scan.c \
        spectmgmt.c \
        sta_info.c \
        status.c \
        tdls.c \
        tkip.c \
        trace.c \
        tx.c \
        util.c \
        vht.c \
        wep.c \
        wme.c \
        wpa.c \
        wbrf.c

# --- Object files ---
OBJ := $(SRC:.c=.o)

# --- Phony targets ---
.PHONY: all clean

# --- Default target ---
all: $(OBJ)

# --- Compilation rule ---
$(OBJ): %.o: %.c
	@echo "  CC  $<"
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean target ---
clean:
	rm -f $(OBJ)

