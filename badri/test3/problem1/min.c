#include "header.h"

// Function to find the minimum node in the BST
BSTNode* findMin(BSTNode* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

