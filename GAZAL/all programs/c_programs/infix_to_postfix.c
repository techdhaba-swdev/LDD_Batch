#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to return the top element of the stack without popping
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Function to check if the character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to get the precedence of the operator
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isOperand(infix[i])) {
            postfix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression!\n");
                return;
            } else {
                pop(stack); // Discard '('
            }
        } else { // Operator
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    // Pop remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }
    postfix[++k] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline if present

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}