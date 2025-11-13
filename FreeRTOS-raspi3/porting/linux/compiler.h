#ifndef __LINUX_COMPILER_H_
#define __LINUX_COMPILER_H_

#ifndef __force
#define __force
#endif

#ifndef __bitwise
#define __bitwise
#endif

#ifndef __rcu
#define __rcu
#endif

#ifndef __iftd
#define __iftd
#endif

#ifndef __counted_by
#define __counted_by(x)
#endif

#ifndef __aligned
#define __aligned(x)
#endif

#ifndef __attribute_const__
#define __attribute_const__
#endif

#ifndef IS_ENABLED
#define IS_ENABLED(x) 0
#endif

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))
#endif

#ifndef __acquires
#define __acquires(x)
#endif
#ifndef __releases
#define __releases(x)
#endif
#ifndef DEFINE_GUARD
#define DEFINE_GUARD(name, type, ...)
#endif

#ifndef __init
#define __init
#endif

#ifndef __must_check
#define __must_check __attribute__((warn_unused_result))
#endif

#ifndef sizeof_field
#define sizeof_field(TYPE, MEMBER) sizeof(((TYPE *)0)->MEMBER)
#endif

#endif /* __LINUX_COMPILER_H_ */
