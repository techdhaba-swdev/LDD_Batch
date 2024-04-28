#include "stack.h"

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        // Stack is full
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        // Stack is empty
        return -1;
    }
    return stack[top--];
}
