#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Structure for a binary tree node
struct TreeNode {
    int data;               // Data stored in the node
    struct TreeNode* left;  // Pointer to the left child node
    struct TreeNode* right; // Pointer to the right child node
};

// Function to create a new node
struct TreeNode* createNode(int data);

// Function to insert a new node into the tree
struct TreeNode* insertNode(struct TreeNode* root, int data);

// Function to perform an in-order traversal of the tree
void inorderTraversal(struct TreeNode* root);

#endif
