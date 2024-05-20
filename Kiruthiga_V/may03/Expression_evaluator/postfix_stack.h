#ifndef POSTFIX_STACK_H
#define POSTFIX_STACK_H
// Stack node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data);
void push(struct Node** top, int data);
int pop(struct Node** top);
int peek(struct Node* top);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

#endif
