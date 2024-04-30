#include "inorder.h"
#include <stdio.h>

//perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left); // Visit left subtree
        printf("%d ", root->data); // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

