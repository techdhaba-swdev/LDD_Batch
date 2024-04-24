#include"stack.h"

typedef struct {
    int items[MAX_SIZE];
    int top;
}Stack;

static Stack stack;


void initialize() {
    stack.top = -1;
}

// Check if the stack is full
bool isFull() {
    return stack.top == MAX_SIZE - 1;
}

// Check if the stack is empty
bool isEmpty() {
    return stack.top == -1;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack.items[stack.top--];
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack.items[++stack.top] = value;
}


