#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100 // setting the max size to 100

// Define the structure for the stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);

#endif
