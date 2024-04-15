#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

// Stack implementation
typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int calculate(const char *expression) {
    Stack stack;
    initialize(&stack);
    int num = 0;
    int sign = 1;
    int result = 0;

    while (*expression) {
        if (isdigit(*expression)) {
            num = num * 10 + (*expression - '0');
        } else if (*expression == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (*expression == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (*expression == '(') {
            push(&stack, result);
            push(&stack, sign);
            result = 0;
            sign = 1;
        } else if (*expression == ')') {
            int prev_sign = pop(&stack);
            int prev_result = pop(&stack);
            result += sign * num;
            result *= prev_sign;
            result += prev_result;
            num = 0;
        }
        expression++;
    }
    result += sign * num;
    return result;
}


int main() {
    // Test cases
    printf("%d\n", calculate("1 + 2"));  // Output: 3
    printf("%d\n", calculate("(1 + 2) * 3"));  // Output: 9
    printf("%d\n", calculate("2 * (3 + 4) - 6"));  // Output: 8
    return 0;
}

