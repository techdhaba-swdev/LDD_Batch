// isEmpty.c

#include "isEmpty.h"
#include <stddef.h>
// Function to check if the stack is empty.
int isEmpty(Stack* stack) {
    return stack->top == NULL; // Return 1 (true) if the stack is empty, 0 (false) otherwise.
}


