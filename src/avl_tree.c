#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

static AVLNode* create_node(int key) {
    AVLNode* node = (AVLNode*) malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

static AVLNode* right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

static AVLNode* left_rotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

static int get_balance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* avl_insert(AVLNode* node, int key) {
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = avl_insert(node->left, key);
    else if (key > node->key)
        node->right = avl_insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

static AVLNode* min_value_node(AVLNode* node) {
    AVLNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

AVLNode* avl_delete(AVLNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = avl_delete(root->left, key);
    else if (key > root->key)
        root->right = avl_delete(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            AVLNode* temp = min_value_node(root->right);

            root->key = temp->key;

            root->right = avl_delete(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = get_balance(root);

    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

AVLNode* avl_search(AVLNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return avl_search(root->left, key);

    return avl_search(root->right, key);
}

void avl_inorder(AVLNode* root) {
    if (root != NULL) {
        avl_inorder(root->left);
        printf("%d ", root->key);
        avl_inorder(root->right);
    }
}

void avl_free(AVLNode* root) {
    if (root != NULL) {
        avl_free(root->left);
        avl_free(root->right);
        free(root);
    }
}
