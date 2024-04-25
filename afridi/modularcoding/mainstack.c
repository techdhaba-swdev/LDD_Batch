// main.c
#include <stdio.h> // Include standard I/O library for printf function
#include "stack.h" // Include the custom stack header file

int main() {
    Stack my_stack; // Declare a stack variable
    init(&my_stack); // Initialize the stack using the init function

    // Push elements onto the stack
    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    // Print the elements of the stack
    printf("Stack elements:\n");
    for (int i = my_stack.top; i >= 0; i--) { // Iterate through the stack
        printf("%s", my_stack[i]); // Print each element
    }

    return 0; // Indicate successful program execution
}

