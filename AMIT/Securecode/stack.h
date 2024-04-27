#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

struct Stack {
    int data[MAX_STACK_SIZE];
    int top;
};

void initializeStack(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack) ;
void push(struct Stack* stack, int value);
int pop(struct Stack* stack) ;
int peek(struct Stack* stack);

#endif
