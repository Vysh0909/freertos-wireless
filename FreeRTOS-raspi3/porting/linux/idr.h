#ifndef __LINUX_IDR_H_
#define __LINUX_IDR_H_

#ifndef idr_for_each_entry
#define idr_for_each_entry(idr, entry, id) \
    for ((entry) = NULL; 0; (entry) = NULL)
#endif

#endif /* __LINUX_IDR_H_ */
