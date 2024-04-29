
#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    initialize(&stack); // Initialize the stack

    // Pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);

    // Popping an element from the stack
    int poppedValue = pop(&stack);
    printf("Popped value: %d\n", poppedValue);

    return 0;
}

