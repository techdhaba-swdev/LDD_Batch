#include "header.h"

// Function to delete a student by ID from the BST
BSTNode* deleteStudent(BSTNode* root, int id) {
    if (root == NULL) {
        return root;
    }
    if (id < root->data.id) {
        root->left = deleteStudent(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteStudent(root->right, id);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteStudent(root->right, temp->data.id);
    }
    return root;
}

