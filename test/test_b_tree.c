#include <stdio.h>
#include "b_tree.h"

int main() {
    BTreeNode* root = btree_create();

    btree_insert(&root, 10);
    btree_insert(&root, 20);
    btree_insert(&root, 5);
    btree_insert(&root, 6);
    btree_insert(&root, 12);
    btree_insert(&root, 30);
    btree_insert(&root, 7);
    btree_insert(&root, 17);

    printf("Inorder traversal of the constructed B-tree is:\n");
    btree_inorder(root);
    printf("\n");

    btree_delete(root, 6);
    printf("Inorder traversal after deletion of 6:\n");
    btree_inorder(root);
    printf("\n");

    btree_free(root);
    return 0;
}
