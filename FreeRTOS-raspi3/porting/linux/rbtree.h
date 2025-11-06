#ifndef __RBTREE_H__
#define __RBTREE_H__

/* Auto-generated stub header: rbtree.h */

/* Minimal stub for struct rb_node and rb_root */
struct rb_node {
    void *rb_left;
    void *rb_right;
    void *rb_parent;
};

struct rb_root {
    struct rb_node *rb_node;
};

#endif /* __RBTREE_H__ */
