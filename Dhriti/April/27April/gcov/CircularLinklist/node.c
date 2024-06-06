#include "node.h"
#include <stdlib.h>

// Function to create a new node with the given data
struct Node* createNode(int data) {

    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode != NULL) 
    {
        //SECURED BY HANDLING MEMORY ALLOCATION FAILURE 
        perror("Memory allocation failed");

        exit(EXIT_FAILURE);
    }
        // Set the data of the new node
        newNode->data = data;

        // Initialize the next pointer to NULL
        newNode->next = NULL;
    
    return newNode;
}

