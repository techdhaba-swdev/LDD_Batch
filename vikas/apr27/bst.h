#ifndef BST_H
#define BST_H

// Structure to represent a node in the BST
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data);

// Function to insert a new node with given data into BST
struct node* insert(struct node* root, int data);

// Function to search for a node with given data in BST
int search(struct node* root, int data);

// Function to perform in-order traversal of BST
void inorderTraversal(struct node* root);

#endif
