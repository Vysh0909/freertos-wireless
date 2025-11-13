#ifndef __LIST_H__
#define __LIST_H__

/* Auto-generated stub header: list.h */
#include "wiphy.h"
#include "gfp.h"
#include "rcupdate.h"
#include "timer.h"
#include "export.h"
#include "spinlock.h"
#include "ewma.h"
#ifndef list_del_init
#define list_del_init(entry)      ((void)0)
#endif

#ifndef list_empty
#define list_empty(head)          (1)   /* always empty for stub */
#endif

#ifndef list_add_rcu
#define list_add_rcu(entry, head)     ((void)0)
#endif

#ifndef list_del_rcu
#define list_del_rcu(entry)           ((void)0)
#endif

#ifndef list_del
#define list_del(entry)               ((void)0)
#endif

#ifndef list_add_tail
#define list_add_tail(entry, head) ((void)0)
#endif

/* Minimal list_head stub for compilation */
struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

/* Dummy macros to allow compilation */
#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

#define LIST_HEAD(name) struct list_head name = { &name, &name }

#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)

#define list_for_each_entry_continue_reverse(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_first_entry_or_null(ptr, type, member) \
    ((ptr)->next != (ptr) ? container_of((ptr)->next, type, member) : NULL)

#define list_first_entry(ptr, type, member) \
    ((ptr)->next ? container_of((ptr)->next, type, member) : NULL)

#define list_last_entry(ptr, type, member) \
    ((ptr)->next ? container_of((ptr)->next, type, member) : NULL)

/*#define list_for_each_entry_rcu(pos, head, member, cond) \
    for (pos = (typeof(pos))((head)->next); pos != NULL; pos = (typeof(pos))(pos->member.next))
*/
#undef list_for_each_entry_rcu
#define list_for_each_entry_rcu(pos, head, member, ...) \
    for (pos = (typeof(pos))((head)->next); \
         pos != NULL; \
         pos = (typeof(pos))(pos->member.next))

#define list_first_or_null_rcu(ptr, type, member) \
    ((ptr)->next != (ptr) ? container_of((ptr)->next, type, member) : NULL)

#define hlist_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != NULL; pos = NULL)

#define hlist_for_each_entry_rcu(pos, head, member) \
    for ((pos) = NULL; (pos) != NULL; (pos) = NULL)

/*#undef list_for_each_entry_rcu // Good practice before redefining
#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); \
         pos != NULL; \
         pos = (typeof(pos))(pos->member.next))
*/
#endif /* __LIST_H__ */
