#include "stack.h"
#include <stdio.h>

int main() {
    Stack stack;
    initialize(&stack);

    // Example usage
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popping elements: %d, %d\n", pop(&stack), pop(&stack));

    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
