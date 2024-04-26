#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop element.\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Function to peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}
