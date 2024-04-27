#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node with the given data
struct node* createNode(int data) {
    // Allocate memory for a new node
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode != NULL){	    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    }
    return newNode;
}

struct node* insert(struct node* root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return createNode(data);
    }

    // Traverse the tree to find the appropriate position for the new node
    if (data < root->data) {
        // If data is less than the current node's data insert into the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // If data is greater than the current node's data, insert into the right subtree
        root->right = insert(root->right, data);
    }

    return root;
}


// Function to search 
int search(struct node* root, int data) {
    // If the tree is empty 
    if (root == NULL) {
        return 0;
    }

    if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        // Search in the left subtree if data is less than the current node's data
        return search(root->left, data);
    } else {
        // Search in the right subtree if data is greater than the current node's data
        return search(root->right, data);
    }
}
void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);  // Traverse left subtree
    printf("%d ", root->data);     // Print current node's data
    inorderTraversal(root->right); // Traverse right subtree
}
// Function to free memory recursively
void freeTree(struct node* root) {
    if (root == NULL) {
        return;
    }

    // Recursively free memory for left and right subtrees
    freeTree(root->left);
    freeTree(root->right);

    // Free memory for the current node
    free(root);
}

