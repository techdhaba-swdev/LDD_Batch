#include"stack.h"

int stack_pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value
    } else {
        int popped = s->data[s->top];
        s->top--;
        return popped;
    }
}
