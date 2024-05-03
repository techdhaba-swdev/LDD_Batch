#include "node.h"
// Function to check if a binary tree is a BST
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) {   // If root is NULL                                               
        return true;  // It is a BST                                                   
    }
    if (root->data < min || root->data > max) { // If root data violates BST property                         
        return false;    // It is not a BST                                                
    }
    return (isBSTUtil(root->left, min, root->data - 1) &&                
            isBSTUtil(root->right, root->data + 1, max));   // Check left subtree  and Check right subtree
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);   // Check if BST property is satisfied
}
