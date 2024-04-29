#include "stack.h"
#include<stdio.h>
// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1; // Initialize top to -1 to indicate an empty stack
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}
