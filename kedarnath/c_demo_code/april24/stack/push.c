#include"push.h"
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack.items[++stack.top] = value;
}

