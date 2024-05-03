#ifndef FUNC_H
#define FUNC_H

// Structure for a node in the stack
struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// Function declarations
void push(StackNode** top, int data);
int pop(StackNode** top);
int isEmpty(StackNode* top);
int peek(StackNode* top);
int isOperator(char ch);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

#endif /* FUNC_H */
