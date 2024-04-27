#include "node.h"
#include <stdlib.h>
#include <stdio.h> // Added for error handling

// Function to create a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data; // Initialize data field
    newNode->left = newNode->right = NULL; // Set both child pointers to NULL
    return newNode;
}
