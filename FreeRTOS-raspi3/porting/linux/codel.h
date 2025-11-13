#ifndef __CODEL_H__
#define __CODEL_H__

struct codel_params {
        unsigned int target;
        unsigned int  interval;
        bool ecn;
};

struct codel_vars { int dummy; };
struct codel_stats {
        unsigned long drop_count;
        unsigned long ecn_mark;
};

#endif
