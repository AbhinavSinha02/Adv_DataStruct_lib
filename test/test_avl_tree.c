#include <stdio.h>
#include "avl_tree.h"

int main() {
    AVLNode* root = NULL;

    root = avl_insert(root, 10);
    root = avl_insert(root, 20);
    root = avl_insert(root, 30);
    root = avl_insert(root, 40);
    root = avl_insert(root, 50);
    root = avl_insert(root, 25);

    printf("Inorder traversal of the constructed AVL tree is:\n");
    avl_inorder(root);
    printf("\n");

    root = avl_delete(root, 40);
    printf("Inorder traversal after deletion of 40:\n");
    avl_inorder(root);
    printf("\n");

    avl_free(root);
    return 0;
}
