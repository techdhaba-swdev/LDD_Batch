#include "stack.h"   // including the stack headerfile
#include <stdio.h>  // including the standred input/output functions

int main() {
    Stack stack;    
    initialize(&stack);  // initiallize the stack

    // pushing some elements
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    // printing the top element
    printf("Top element: %d\n", peek(&stack));
    // printing the poping elements
    printf("Popping elements: %d, %d\n", pop(&stack), pop(&stack));
    // printing the top element after the poping
    printf("Top element after popping: %d\n", peek(&stack));

    return 0;  // executing the programe withot errors
}
