#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "postfix_stack.h"
// Stack functions
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
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
    struct Node* stack = NULL;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard the '('
        } else { // Operator
            while (stack != NULL && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }
    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    struct Node* stack = NULL;
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
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
        i++;
    }
    return pop(&stack);
}


