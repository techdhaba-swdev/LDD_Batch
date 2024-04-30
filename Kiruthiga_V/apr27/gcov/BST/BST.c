#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
struct node* createNode(int data) {    // Function to create a new node
    // Allocate memory for a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize node data and child pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct node* insert(struct node* root, int data) {
    // If tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(data);
    }
    // Insert data into left subtree if it's smaller
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Insert data into right subtree if it's larger
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data already exists, do nothing
    return root;
}

// Function to search for a node with given data in the BST
int search(struct node* root, int data) {
    // If tree is empty or data is not found, return 0
    if (root == NULL) {
        return 0;
    }
    // If data is found, return 1
    if (root->data == data) {
        return 1;
    }
    // Recursively search in left subtree if data is smaller
    else if (data < root->data) {
        return search(root->left, data);
    }
    // Recursively search in right subtree if data is larger
    else {
        return search(root->right, data);
    }
}

// Function for in-order traversal of the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        // Traverse left subtree
        inorderTraversal(root->left);
        // Print root node data
        printf("%d ", root->data);
        // Traverse right subtree
        inorderTraversal(root->right);
    }
}
