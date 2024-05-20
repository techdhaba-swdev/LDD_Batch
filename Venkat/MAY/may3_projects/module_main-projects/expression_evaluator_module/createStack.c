// createStack.c

#include "createStack.h"
#include <stdlib.h>
#include <stdio.h>

// Function to create and initialize a new stack.
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Allocate memory for the stack.
    if (stack == NULL) {
        printf("Error: Memory not allocated for stack\n"); // Error handling for memory allocation.
        exit(EXIT_FAILURE);
    }
    stack->top = NULL; // Initialize the top of the stack to NULL.
    return stack; // Return the pointer to the new stack.
}


