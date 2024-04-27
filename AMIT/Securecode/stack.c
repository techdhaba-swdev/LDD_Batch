#include <stdio.h>
#include <stdlib.h>
#include"stack.h"
#include<limits.h>

int main() {
    struct Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Top element after pop: %d\n", peek(&myStack));

    return 0;
}

