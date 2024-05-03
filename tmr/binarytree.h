#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Node structure definition
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function declarations
struct Node* createNode(int data);
void preorderTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
int isBinarySearchTree(struct Node* root);
int findHeight(struct Node* root);
void findMinMaxValues(struct Node* root, int* min, int* max);

#endif
