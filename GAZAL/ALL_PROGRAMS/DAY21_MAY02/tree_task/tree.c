#include "tree.h" // Include the header file for function prototypes (used to secure multiple inclusion)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Secure: Ensures proper memory allocation
    if (newNode == NULL) { // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); // Exit the program if memory allocation fails
    }
    newNode->data = data; // Initialize the data of the new node
    newNode->left = NULL; // Initialize the left child pointer of the new node
    newNode->right = NULL; // Initialize the right child pointer of the new node
    return newNode; // Return the newly created node
}

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {  // Base case: Empty tree, create a new root node
        return createNode(data); // Create a new node with the given data
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
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

// Function to calculate the sum of all nodes in the binary tree
int sumOfNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // Base case: Empty tree, return 0
    }
    int sum = root->data; // Add current node's data
    sum += sumOfNodes(root->left); // Recursively add sum of left subtree
    sum += sumOfNodes(root->right); // Recursively add sum of right subtree
    return sum; // Return the sum of node values
}

// Function to deallocate memory for the binary tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left); // Free left subtree
        freeTree(root->right); // Free right subtree
        free(root); // Free current node
    }
}
