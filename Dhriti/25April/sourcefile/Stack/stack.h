#ifndef STACK_H_
#define STACK_H_

#define MAX_SIZE 100

// Define the structure of the stack
struct Stack {
    int items[MAX_SIZE];  // Array to store stack elements
    int top;              // Index of the top element of the stack
};

// Function prototypes
void initializeStack(struct Stack *stack);
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
void push(struct Stack *stack, int value);
int pop(struct Stack *stack);
int peek(struct Stack *stack);

#endif 

