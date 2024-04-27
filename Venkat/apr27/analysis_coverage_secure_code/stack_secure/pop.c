#include <stdio.h>
#include "stack.h"

int pop(stack *s) {
        if (isEmpty(s)) {
                printf("stack is underflow\n");
                return -1;
        }
        return s->items[s->top--];
}

