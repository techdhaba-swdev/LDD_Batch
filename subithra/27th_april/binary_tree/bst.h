#ifndef BST_H
#define BST_H

// Structure declaration for a node in the Binary Search Tree (BST)
struct node;

// Function declarations

// Function to create a new node with the given data
struct node* createNode(int data);

// Function to insert a new node with the given data into the BST
struct node* insert(struct node* root, int data);

// Function to search for a node with the given data in the BST
int search(struct node* root, int data);

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root);

// Function to deallocate memory for the entire BST
void destroyTree(struct node* root);

#endif
