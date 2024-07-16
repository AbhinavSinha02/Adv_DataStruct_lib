#include <stdio.h>
#include "red_black_tree.h"

int main() {
    RBNode* root = NULL;

    root = rb_insert(root, 10);
    root = rb_insert(root, 20);
    root = rb_insert(root, 30);
    root = rb_insert(root, 40);
    root = rb_insert(root, 50);
    root = rb_insert(root, 25);

    printf("Inorder traversal of the constructed Red-Black tree is:\n");
    rb_inorder(root);
    printf("\n");

    root = rb_delete(root, 40);
    printf("Inorder traversal after deletion of 40:\n");
    rb_inorder(root);
    printf("\n");

    rb_free(root);
    return 0;
}
