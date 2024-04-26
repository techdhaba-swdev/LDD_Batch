#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define maximum size of the stack
#define MAX_SIZE 100

// Structure to represent the stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif
