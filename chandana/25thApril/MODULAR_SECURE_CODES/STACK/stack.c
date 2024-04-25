#include "stack.h"    // Include the header file that contains the structure definition and function prototypes

// Initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;  // Initialize the top index to -1 (empty stack)
}

// Check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;  // If top index is equal to MAX_SIZE - 1, stack is full
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;  // If top index is -1, stack is empty
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");  // Print an error message if stack is full
        return;
    }
    stack->top++;              // Increment top index
    stack->items[stack->top] = value;  // Add value to the stack
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");  // Print an error message if stack is empty
        return -1;
    }
    int value = stack->items[stack->top];  // Get the top element
    stack->top--;              // Decrement top index
    return value;              // Return the popped value
}

// Peek at the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");  // Print an error message if stack is empty
        return -1;
    }
    return stack->items[stack->top];  // Return the top element without removing it
}

// Display the stack elements
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");  // Print an error message if stack is empty
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);  // Print each element from top to bottom
    }
    printf("\n");

}
