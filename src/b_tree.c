#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

BTreeNode* btree_create() {
    BTreeNode* node = (BTreeNode*) malloc(sizeof(BTreeNode));
    node->leaf = 1;
    node->n = 0;
    return node;
}

// Add more functions to handle insertion, deletion, search...

void btree_inorder(BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf) {
            btree_inorder(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf) {
        btree_inorder(root->children[i]);
    }
}

void btree_free(BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i <= root->n; i++) {
            btree_free(root->children[i]);
        }
        free(root);
    }
}
