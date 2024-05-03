#include "node.h"
// Function to find the height of the BST
int height(struct Node* root) {
    if (root == NULL) {   // If root is NULL                                               
        return -1;  // Height is -1                                                     
    }
    int leftHeight = height(root->left); // Height of left subtree                                
    int rightHeight = height(root->right);  // Height of right subtree                             
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);  // Return maximum height + 1
}
