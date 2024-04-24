#include "stack1.h"

void init(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Or any other error handling mechanism
    }
    int value = stack->items[stack->top];
    stack->top--;
    return value;
}
