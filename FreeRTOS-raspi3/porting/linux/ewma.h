struct ewma {
    unsigned long internal;
    unsigned long factor;
    unsigned long weight;
};

#undef DECLARE_EWMA
#define DECLARE_EWMA(name, factor, weight) \
    /* Use positional initialization to avoid designated initializer conflicts */ \
	struct ewma name = { 0, (factor), (weight) };
