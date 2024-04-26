#include <stdio.h>
#include "node.h"
#include <stdlib.h> // Include standard library for memory allocation

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) { // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Terminate the program
    }
    newNode->data = data; // Assign data to the new node
    newNode->prev = NULL; // Set previous pointer to NULL
    newNode->next = NULL; // Set next pointer to NULL
    return newNode; // Return the new node
}
