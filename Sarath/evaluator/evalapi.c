#include "eval.h"
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(StackNode** top, int data) {
    StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

int peek(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return top->data;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    StackNode* stack = NULL;
    int i = 0, j = 0;
    while (infix[i]) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            i++;
            continue;
        }
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
            while (isdigit(infix[i]))
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[j++] = pop(&stack);
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression.\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack);
            }
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[j++] = pop(&stack);
            push(&stack, infix[i++]);
        } else {
            printf("Invalid character in expression.\n");
            exit(EXIT_FAILURE);
        }
    }
    while (!isEmpty(stack))
        postfix[j++] = pop(&stack);
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    StackNode* stack = NULL;
    int i = 0;
    while (postfix[i]) {
        if (postfix[i] == ' ' || postfix[i] == '\t') {
            i++;
            continue;
        }
        if (isdigit(postfix[i])) {
            int operand = 0;
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            push(&stack, operand);
        } else if (isOperator(postfix[i])) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
            }
            i++;
        }
    }
    return pop(&stack);
}
