#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

// Struct representing a stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);

#endif
