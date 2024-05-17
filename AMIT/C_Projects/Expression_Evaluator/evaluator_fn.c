#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"infix.h"


struct StackNode* createStackNode(double value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void push(struct StackNode** stack, double value) {
    struct StackNode* newNode = createStackNode(value);
    newNode->next = *stack;
    *stack = newNode;
}

double pop(struct StackNode** stack) {
    if (*stack == NULL) {
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    double value = (*stack)->value;
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

// Operator precedence
int precedence(char op) {        //for priority
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
      
        default:
            return 0;
    }
}

// Convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix) {      //create infix to postfix ex. 2+3*4  convert 234*+
    struct StackNode* stack = NULL;                           
    int j = 0;                                                  //empty stack to push and pop   

    for (int i = 0; infix[i]; ++i) {                            
        char c = infix[i];
        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            --i;                                      // Move back to the last digit
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (stack && stack->value != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            pop(&stack); // Remove '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (stack && precedence(c) <= precedence(stack->value)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, c);
        }
    }

    while (stack) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

// Evaluate postfix expression
double evaluatePostfix(const char* postfix) {    //evaluating postfix function 
    struct StackNode* stack = NULL;
    int i = 0;

    while (postfix[i]) {
        char c = postfix[i];
        if (isdigit(c)) {
            double operand = 0;
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                ++i;
            }
            push(&stack, operand);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            switch (c) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
            }
            ++i;
        } else {
            ++i; // Skip spaces
        }
    }

    return pop(&stack);
}
