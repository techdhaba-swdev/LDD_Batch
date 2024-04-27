#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
    if (newNode == NULL) { // Check if memory allocation failed
        printf("Memory allocation failed\n");
	free(newNode); //Free memory allocated for newNode
	exit(1);
    }
    newNode->data = data; // Initialize the data field of the new node
    newNode->left = NULL; // Initialize the left child pointer of the new node to NULL
    newNode->right = NULL; // Initialize the right child pointer of the new node to NULL
    return newNode; // Return the newly created node
}

// Function to insert a new node into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data); // If the tree is empty, create a new node as the root
    }
    if (data < root->data) {
        root->left = insert(root->left, data); // If data is less than the root, insert into the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // If data is greater than the root, insert into the right subtree
    }
    return root; // Return the root of the updated tree
}

// Function to search for a node with the given data in the BST
int search(struct node* root, int data) {
    if (root == NULL) {
        return 0; // If the tree is empty, return 0 (not found)
    }
    if (root->data == data) {
        return 1; // If the root node contains the data, return 1 (found)
    } else if (data < root->data) {
        return search(root->left, data); // Search in the left subtree
    } else {
        return search(root->right, data); // Search in the right subtree
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left); // Traverse the left subtree
        printf("%d ", root->data); // Print the data of the root node
        inorderTraversal(root->right); // Traverse the right subtree
    }
}
