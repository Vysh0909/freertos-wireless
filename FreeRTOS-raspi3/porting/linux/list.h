#ifndef __LIST_H__
#define __LIST_H__

/* Auto-generated stub header: list.h */
#include "wiphy.h"
#include "gfp.h"
#include "rcupdate.h"

/* Minimal list_head stub for compilation */
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

/* Dummy macros to allow compilation */
#define LIST_HEAD(name) struct list_head name = { &name, &name }

#define list_for_each_entry_continue_reverse(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#endif /* __LIST_H__ */
