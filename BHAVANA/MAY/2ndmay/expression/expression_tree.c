#include <stdio.h>
#include <stdlib.h>
#include "expression_tree.h"

// Function to create a new stack node
struct StackNode* newStackNode(char data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, char data) {
    struct StackNode* stackNode = newStackNode(data);
    stackNode->next = *top;
    *top = stackNode;
}

// Function to pop a node from the stack
char pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return '\0';
    }
    char popped = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix notation using Shunting Yard algorithm
void infixToPostfix(char* infix, char* postfix) {
    struct StackNode* stack = NULL;
    int j = 0; // Index for postfix expression

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == ' ')
            continue;

        if (!isOperator(infix[i])) {
            postfix[j++] = infix[i];
        } else {
            while (stack != NULL && precedence(infix[i]) <= precedence(stack->data)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to evaluate postfix expression using a stack
int evaluatePostfix(char* postfix) {
    struct StackNode* stack = NULL;

    for (int i = 0; postfix[i]; i++) {
        if (postfix[i] == ' ')
            continue;

        if (!isOperator(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}
