#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Function to create a new node
struct TreeNode* createNode(int data) {
    // Allocate memory for the new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Initialize the new node
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        return createNode(data);
    }
    // If the data is less than the current node's data, insert into the left subtree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // If the data is greater than the current node's data, insert into the right subtree
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to perform an in-order traversal of the tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        // Traverse the left subtree
        inorderTraversal(root->left);
        // Visit the current node
        printf("%d ", root->data);
        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}
