#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

static RBNode* create_node(int key) {
    RBNode* node = (RBNode*) malloc(sizeof(RBNode));
    node->key = key;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void rb_inorder(RBNode* root) {
    if (root != NULL) {
        rb_inorder(root->left);
        printf("%d ", root->key);
        rb_inorder(root->right);
    }
}

void rb_free(RBNode* root) {
    if (root != NULL) {
        rb_free(root->left);
        rb_free(root->right);
        free(root);
    }
}
