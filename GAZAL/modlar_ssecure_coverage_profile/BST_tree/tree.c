#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the BST
struct node {
    int data;               // Data stored in the node
    struct node* left;      // Pointer to the left child node
    struct node* right;     // Pointer to the right child node
};
// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) {                       // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);   // Terminate program if memory allocation failed
     }
    newNode->data = data;                        // Set data of the new node
    newNode->left = NULL;                        // Initialize left child pointer to NULL
    newNode->right = NULL;                       // Initialize right child pointer to NULL
    return newNode;                             // Return pointer to the new node
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {                          // If tree is empty
        return createNode(data);                 // Create a new node and return as the root
    }

    if (data < root->data) {                     // If data is less than current node's data
        root->left = insert(root->left, data);   // Recursively insert into the left subtree
    } else if (data > root->data) {              // If data is greater than current node's data
        root->right = insert(root->right, data); // Recursively insert into the right subtree
    }

    return root;                                 // Return the updated root node
}

// Function to search for a node with given data in the BST
int search(Node* root, int data) {
    if (root == NULL) {                          // If tree is empty or node not found
        return 0;                                // Return 0 (not found)
    }

    if (root->data == data) {                    // If current node's data matches the search data
        return 1;                                // Return 1 (found)
    } else if (data < root->data) {              // If search data is less than current node's data
        return search(root->left, data);         // Recursively search in the left subtree
    } else {                                     // If search data is greater than current node's data
        return search(root->right, data);        // Recursively search in the right subtree
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {                          // If tree is not empty
        inorderTraversal(root->left);            // Traverse left subtree
        printf("%d ", root->data);               // Print data of current node
        inorderTraversal(root->right);           // Traverse right subtree
    }
}
