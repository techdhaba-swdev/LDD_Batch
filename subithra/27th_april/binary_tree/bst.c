#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Structure definition for a node in the Binary Search Tree (BST)
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node with the given data
struct node* createNode(int data) {
    // Allocate memory for the new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    // Initialize the node's data and child pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    // Return the newly created node
    return newNode;
}

// Function to insert a new node with the given data into the BST
struct node* insert(struct node* root, int data) {
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL) {
        return createNode(data);
    }

    //Insert the data into the appropriate subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the root of the modified tree
    return root;
}

// Function to search for a node with the given data in the BST
int search(struct node* root, int data) {
    // If the tree is empty or the data is not found, return 0
    if (root == NULL) {
        return 0;
    }

    // If the data is found, return 1
    if (root->data == data) {
        return 1;
    }
    
    // Search in the left subtree if the data is less than the current node's data
    // or in the right subtree if the data is greater than the current node's data
    else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root) {
    //If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree, visit the current node, and then traverse the right subtree
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to deallocate memory for the entire BST
void destroyTree(struct node* root) {
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    //Deallocate memory for the left subtree, right subtree, and then the current node
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
