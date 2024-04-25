#include "stack.h"
#include <stdio.h>
void stack_init(Stack *s) {
    s->top = -1;
}

void stack_push(Stack *s, int data) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = data;
    } else {
        printf("Error: Stack is full. Cannot push element.\n");
    }
}

int stack_pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Error: Stack is empty. Cannot pop element.\n");
        return -1;
    }
    }

bool stack_is_empty(Stack *s) {
    return s->top == -1;
}

bool stack_is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
