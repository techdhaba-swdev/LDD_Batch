// push.c

#include "push.h"
#include <stdlib.h>
#include <stdio.h>

// Function to push a new integer data onto the stack.
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node.
    if (newNode == NULL) {
        printf("Error: Memory not allocated for new node\n"); // Error handling for memory allocation.
        exit(EXIT_FAILURE);
    }
    newNode->data = data; // Set the data for the new node.
    newNode->next = stack->top; // Link the new node to the current top node.
    stack->top = newNode; // Update the top pointer to the new node.
}
