#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Print error message if memory allocation fails
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Initialize node's data and children pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {  // Base case: Empty tree, create a new root node
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree for smaller values
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree for larger values
    } else { // Handle duplicates (optional: can modify to overwrite or reject)
        // printf("Duplicate value: %d\n", data);
    }

    return root;  // Return the (potentially modified) root node
}

// Function to perform in-order traversal of the binary tree
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

// Function to free memory allocated for the binary tree
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);   // Free left subtree
        freeTree(root->right);  // Free right subtree
        free(root);             // Free current node
    }
}

// Function to calculate the sum of all nodes in the binary tree
int sumNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }
}
