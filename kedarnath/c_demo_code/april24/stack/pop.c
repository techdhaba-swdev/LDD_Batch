#include"pop.h"
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack.items[stack.top--];
}

