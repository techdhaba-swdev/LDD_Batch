#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include"stack.h"


// Initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return INT_MIN;
    }
    return stack->data[stack->top--];
}

// Peek at the top element without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack->data[stack->top];
}

