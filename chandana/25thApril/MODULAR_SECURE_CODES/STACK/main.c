#include "stack.h"    // Include the header file that contains the structure definition and function prototypes
#include <stdio.h>    // Include standard I/O functions

int main() {
    Stack stack;        // Declare a stack
    initializeStack(&stack);  // Initialize the stack

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the stack
    display(&stack);

    // Peek at the top element
    printf("Top element: %d\n", peek(&stack));

    // Pop an element from the stack
    printf("Popped element: %d\n", pop(&stack));

    // Display the stack after popping
    display(&stack);

    return 0;
}
