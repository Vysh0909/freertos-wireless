#ifndef __UTSNAME_H__
#define __UTSNAME_H__

/* Auto-generated stub header: utsname.h */
struct new_utsname {
    char sysname[32];
    char nodename[32];
    char release[32];
    char version[32];
    char machine[32];
    char domainname[32];
};

/* Provide a static function returning a pointer to this struct */
static inline struct new_utsname *init_utsname(void)
{
    static struct new_utsname uts = {
        .sysname = "Linux",
        .nodename = "localhost",
        .release = "5.10.0-porting",
        .version = "#1 SMP PREEMPT",
        .machine = "arm64",
        .domainname = "local"
    };
    return &uts;
}

#endif /* __UTSNAME_H__ */
