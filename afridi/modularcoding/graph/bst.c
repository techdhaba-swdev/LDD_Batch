#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node* insert(Node* root, int data) {
    // Implementation...
}

// Other function implementations...
