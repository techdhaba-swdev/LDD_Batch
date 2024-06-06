#include "stack.h"
#include <stdio.h>

int main() {
    struct Stack stack;  // Declare a stack variable
    initializeStack(&stack);  // Initialize the stack

    push(&stack, 5);  // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 15);

    printf("Top element of stack: %d\n", peek(&stack));  // Peek at the top element

    printf("Popped item: %d\n", pop(&stack));  // Pop an element from the stack
    printf("Top element of stack: %d\n", peek(&stack));  // Peek at the top element

    return 0;
}

