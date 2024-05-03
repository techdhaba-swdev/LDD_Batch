#include "node.h"
// Function to find the minimum value in the BST
struct Node* findMin(struct Node* root) {
    if (root == NULL) {// If root is NULL
        return NULL;// Return NULL
    }
    if (root->left == NULL) {// If left child is NULL
        return root;// Return the root
    }
    return findMin(root->left);// Recursively find minimum in the left subtree
}
