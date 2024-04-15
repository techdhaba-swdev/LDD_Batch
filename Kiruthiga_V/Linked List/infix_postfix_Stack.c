#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// Function to create a new stack node
StackNode* createNode(char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(StackNode* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(StackNode** top_ref, char data) {
    StackNode* newNode = createNode(data);
    newNode->next = *top_ref;
    *top_ref = newNode;
}

// Function to pop an element from the stack
char pop(StackNode** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    StackNode* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top element of the stack without popping it
char peek(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return top->data;
}

// Function to return the precedence of an operator
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix notation
char* infixToPostfix(char* infix) {
    StackNode* stack = NULL;
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression.\n");
                exit(1);
            } else {
                pop(&stack); // Pop '('
            }
        } else {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    return postfix;
}

// Main function to test infix to postfix conversion
int main() {
    char infix[] = "a + b * c";
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", infixToPostfix(infix));
    return 0;
}


