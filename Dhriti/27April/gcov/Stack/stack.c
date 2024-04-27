#include "stack.h"
#include <stdio.h>

// Function to initialize stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;  // Initialize top index to -1 (empty stack)
}

// Function to check if stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;  // Return 1 if stack is empty, 0 otherwise
}

// Function to check if stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;  // Return 1 if stack is full, 0 otherwise
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {  // Check if stack is full
        printf("Stack overflow\n");  // Print error message
        return;
    }
    stack->items[++stack->top] = value;  // Increment top index and insert element
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {  // Check if stack is empty
        printf("Stack underflow\n");  // Print error message
        return -1;
    }
    return stack->items[stack->top--];  // Return and decrement top element
}

// Function to get the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {  // Check if stack is empty
        printf("Stack is empty\n");  // Print error message
        return -1;
    }
    return stack->items[stack->top];  // Return top element of the stack
}

