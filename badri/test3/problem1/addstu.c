#include "header.h"

//function to add a student to the BST
BSTNode* addStudent(BSTNode* root, Student data) {
    if (root == NULL) {
        return createBSTNode(data);
    }
    if (data.id < root->data.id) {
        root->left = addStudent(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = addStudent(root->right, data);
    } else {
        printf("Student with ID %d already exists.\n", data.id);
    }
    return root;
}

