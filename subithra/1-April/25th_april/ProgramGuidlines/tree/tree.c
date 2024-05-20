#include "tree.h" // Include the header file containing the TreeNode structure and function prototypes
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data; // Data of the node
    struct TreeNode* left; // Pointer to the left child
    struct TreeNode* right; // Pointer to the right child
};
// Create a new tree node
struct TreeNode* createNode(int data) {
    // Allocate memory for the new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // Check if memory allocation failed
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n"); // Print an error message
        exit(EXIT_FAILURE); // Exit the program
    }
    newNode->data = data; // Set the data of the new node
    newNode->left = NULL; // Initialize the left child pointer to NULL
    newNode->right = NULL; // Initialize the right child pointer to NULL
    return newNode; // Return the new node
}

// Insert a node into the tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) { // If the tree is empty, create a new node and return it
        return createNode(data);
    }
    if (data < root->data) { // If the data is less than the root data, insert into the left subtree
        root->left = insertNode(root->left, data);
    } else if (data > root->data) { // If the data is greater than the root data, insert into the right subtree
        root->right = insertNode(root->right, data);
    }
    return root; // Return the root of the tree
}

// Inorder traversal of the tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) { // If the root is not NULL
        inorderTraversal(root->left); // Traverse the left subtree
        printf("%d ", root->data); // Print the data of the current node
        inorderTraversal(root->right); // Traverse the right subtree
    }
}
