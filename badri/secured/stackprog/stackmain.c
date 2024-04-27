#include "stack.h" // include the header file for stack operations
#include <stdio.h> // include standard input - output library

int main() {
    Stack stack; // Declare a stack variable
    initialize(&stack); // initialize the stack

    // Example usage pushing 10 20 30 into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack)); // print the top element of the stack

    printf("Popping elements: %d, %d\n", pop(&stack), pop(&stack)); //pop two elements from the stack 

    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No"); // check if the stack is empty and print the result

    return 0; //return 0 to indicate successful termination
}
