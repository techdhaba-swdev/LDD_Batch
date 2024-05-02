#include "bstadd.h"
#include <stdlib.h>
#include <stdio.h>

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Check for memory allocation failure
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialize node data and pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node
        root = createNode(data);
    } else {
        // Otherwise, insert the node recursively based on data value
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
return root;
}

// Function to add numbers in the binary tree
int addNumbers(struct Node* root) {
    if (root == NULL) {
        // Base case: if root is NULL, return 0
        return 0;
    } else {
        // Recursively calculate sum of all nodes
        return root->data + addNumbers(root->left) + addNumbers(root->right);
    }
}

void printInorder(struct Node* root){
	if(root != NULL){
		printInorder(root->left);
		printf("%d",root->data);
		printInorder(root->right);
	}
}
