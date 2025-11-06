#ifndef __LIST_H__
#define __LIST_H__

/* Auto-generated stub header: list.h */
#include "wiphy.h"

#ifndef list_for_each_entry
#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); pos != NULL; pos = NULL)
#endif

#ifndef _LINUX_LIST_H

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};
#endif

#endif /* __LIST_H__ */
