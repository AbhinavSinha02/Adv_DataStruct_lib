#ifndef B_TREE_H
#define B_TREE_H

#define T 3 // Minimum degree (defines the range for number of keys)

typedef struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode *children[2 * T];
    int n;
    int leaf;
} BTreeNode;

BTreeNode* btree_create();
void btree_insert(BTreeNode** root, int key);
void btree_delete(BTreeNode* root, int key);
BTreeNode* btree_search(BTreeNode* root, int key);
void btree_inorder(BTreeNode* root);
void btree_free(BTreeNode* root);

#endif // B_TREE_H
