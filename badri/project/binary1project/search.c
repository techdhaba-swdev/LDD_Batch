#include "node.h"
// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {// If root is NULL or matches the data
        return root; // Return the root
    }
    if (data < root->data) {// If data is less than root data
        return search(root->left, data);// Search in the left subtree
    }
    return search(root->right, data);// Search in the right subtree
									 
}
