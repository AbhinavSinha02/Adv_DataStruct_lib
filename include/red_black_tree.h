#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int key;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

RBNode* rb_insert(RBNode* root, int key);
RBNode* rb_delete(RBNode* root, int key);
RBNode* rb_search(RBNode* root, int key);
void rb_inorder(RBNode* root);
void rb_free(RBNode* root);

#endif 
