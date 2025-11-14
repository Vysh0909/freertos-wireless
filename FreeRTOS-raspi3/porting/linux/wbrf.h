#ifndef __WBRF_STUBS_H__
#define __WBRF_STUBS_H__

#include "types.h"

/* Minimal WBRF structures to satisfy compilation */
struct wbrf_range {
    u32 start;
    u32 end;
};

struct wbrf_ranges_in_out {
    struct wbrf_range band_list[4];
    u32 num_of_ranges;
};

/* Record add/remove types */
#define WBRF_RECORD_ADD    1
#define WBRF_RECORD_REMOVE 2

/* Stub for ACPI WBRF handler */
static inline void acpi_amd_wbrf_add_remove(void *dev, int op,
                                            struct wbrf_ranges_in_out *ranges)
{
    /* Do nothing (stub) */
}

#endif

