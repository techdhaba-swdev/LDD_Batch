#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

// Define a struct to represent a node in the BST
struct node {
int data; // The integer value stored in the node
struct node* left; // Pointer to the left child node
struct node* right; // Pointer to the right child node
};

// Function to create a new node
struct node* createNode(int data);

// Function to insert a new node into the BST
struct node* insert(struct node* root, int data);

// Function to search for a node with the given data in the BST
int search(struct node* root, int data);

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root);

#endif /*BINARYSEARCH _H */
