#include"stack.h"

void stack_push(Stack *s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        s->top++;
        s->data[s->top] = data;
    }
}

