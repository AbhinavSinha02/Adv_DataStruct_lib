#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode* avl_insert(AVLNode* node, int key);
AVLNode* avl_delete(AVLNode* node, int key);
AVLNode* avl_search(AVLNode* root, int key);
void avl_inorder(AVLNode* root);
void avl_free(AVLNode* root);

#endif // AVL_TREE_H
