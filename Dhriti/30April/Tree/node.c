#include <stdlib.h>
#include "node.h"

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   // SECURED: MEMORY ALLOCATION FALIURE
    if (newNode == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    // Initialize the data and pointers of the new node
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

