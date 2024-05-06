#include "evaluator.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct StackNode {
    char data;
    struct StackNode* next;
};


static struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static int isEmpty(struct StackNode* root) {
    return !root;
}

static void push(struct StackNode** root, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *root;
    *root = newNode;
}

static char pop(struct StackNode** root) {
    if (isEmpty(*root))
        return '\0';
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

static char peek(struct StackNode* root) {
    if (isEmpty(root))
        return '\0';
    return root->data;
}

static int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

static int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char* expression) {
    struct StackNode* stack = NULL;
    int length = strlen(expression);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; expression[i]; i++) {
        if (isalnum(expression[i])) {
            postfix[j++] = expression[i];
        }
        
        else if (expression[i] == '(') {
            push(&stack, expression[i]);
        }
        
        else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        }
     
        else if (isOperator(expression[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(expression[i])) {
                postfix[j++] = pop(&stack);
            }
            
            push(&stack, expression[i]);
        }
    }

    
    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    return postfix;
}


int evaluatePostfix(char* expression) {
    struct StackNode* stack = NULL;
    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
       
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        }
        
        else if (isOperator(expression[i])) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
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
