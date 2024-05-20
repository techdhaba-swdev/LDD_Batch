// pop.c

#include "pop.h"
#include <stdlib.h>
#include <stdio.h>

// Function to pop the top data from the stack.
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow\n"); // Error handling for empty stack.
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top; // Temporary node to hold the top node.
    int data = temp->data; // Retrieve data from the top node.
    stack->top = temp->next; // Move the top pointer to the next node.
    free(temp); // Free the memory of the popped node.
    return data; // Return the popped data.
}


