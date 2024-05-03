#include "stack.h"  // Include header file for stack structure definition (assumed)
#include <stdlib.h>  // Include standard library for memory allocation (malloc, free)
#include <stdio.h>   // Include standard input/output header (printf)

// Function to push data onto stack
void push(Stack* stack, char data) {
    // Create a new node for the data
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Set data and next pointer of the new node
    newNode->data = data;
    newNode->next = stack->top;

    // Update the top pointer of the stack to point to the new node
    stack->top = newNode;
}

// Function to pop data from stack
char pop(Stack* stack) {
    // Check if stack is empty
    if (is_empty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    // Store the top node and its data
    Node* temp = stack->top;
    char data = temp->data;

    // Update the top pointer to point to the next node
    stack->top = temp->next;

    // Free the memory used by the popped node
    free(temp);

    // Return the popped data
    return data;
}

// Function to peek at the top of the stack
char peek(Stack* stack) {
    // Check if stack is empty
    if (is_empty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    // Return the data of the top node without removing it
    return stack->top->data;
}

// Function to check if stack is empty
int is_empty(Stack* stack) {
    // Return true if the top pointer is NULL (empty stack)
    return stack->top == NULL;
}
