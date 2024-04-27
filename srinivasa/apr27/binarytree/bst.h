#ifndef BST_H
#define BST_H

// Define the node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data);

// Function to insert a new node into the BST
struct node* insert(struct node* root, int data);

// Function to search for a node with the given data
int search(struct node* root, int data);

// Function to perform in-order traversal
void inorderTraversal(struct node* root);

#endif
