#include "header.h"

// Function to search for a student by ID in the BST
BSTNode* searchStudent(BSTNode* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return searchStudent(root->left, id);
    }
    return searchStudent(root->right, id);
}

