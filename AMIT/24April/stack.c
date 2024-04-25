#include "stack.h"



int main() {
    Stack my_stack;
    stack_init(&my_stack);

    stack_push(&my_stack, 10);
    stack_push(&my_stack, 20);
    stack_push(&my_stack, 30);

    printf("Popped element: %d\n", stack_pop(&my_stack));
    printf("Is stack empty? %s\n", stack_is_empty(&my_stack) ? "true" : "false");
    printf("Is stack full? %s\n", stack_is_full(&my_stack) ? "true" : "false");

    return 0;
}
