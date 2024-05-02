#include "btree.h"//includes header file btree.h which allow to use structure,function prototype from header file
#include <stdio.h>//standard libraries for printf scanf
#include <stdlib.h>//standard libraries for malloc functions

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize node's data and child pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        return createNode(data);
    }
    
    // If data is less than current node's data, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than current node's data, insert into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Handle duplicates 
    else {
        printf("Duplicate value: %d\n", data);
    }
    
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        // Traverse left subtree
        inOrder(root->left);
        // Visit current node
        printf("%d ", root->data);
        // Traverse right subtree
        inOrder(root->right);
    }
}

// Function to add all the values in the binary tree
int sumAll(struct Node* root) {
    //  if root is NULL , return 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursive  add the current node's value
    // to the sum of values in its left and right subtrees
    int sum = root->data;
    sum += sumAll(root->left);
    sum += sumAll(root->right);
    
    return sum;
}

