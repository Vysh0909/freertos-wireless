#ifndef __CODEL_H__
#define __CODEL_H__

#define CODEL_DISABLED_THRESHOLD 0
struct codel_params {
        unsigned int target;
        unsigned int  interval;
        bool ecn;
	int ce_threshold;
    int ce_threshold_selector;
    int ce_threshold_mask;
};

struct codel_vars { int dummy; };
struct codel_stats {
        unsigned long drop_count;
        unsigned long ecn_mark;
};

#endif
