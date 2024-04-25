#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h> // Include boolean data type

#define MAX_SIZE 100  // Maximum size of the stack

// Define a structure for the stack
typedef struct {
    int items[MAX_SIZE];  // Array to store the stack items
    int top;              // Index of the top element
} Stack;

// Function prototypes
void initializeStack(Stack *stack);         // Initialize the stack
bool isFull(Stack *stack);                   // Check if the stack is full
bool isEmpty(Stack *stack);                  // Check if the stack is empty
void push(Stack *stack, int value);         // Push an element onto the stack
int pop(Stack *stack);                      // Pop an element from the stack
int peek(Stack *stack);                     // Peek at the top element of the stack
void display(Stack *stack);                 // Display the stack elements

#endif
