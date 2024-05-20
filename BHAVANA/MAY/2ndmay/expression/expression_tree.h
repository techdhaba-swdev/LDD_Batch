#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdbool.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

struct StackNode* newStackNode(char data);
void push(struct StackNode** top, char data);
char pop(struct StackNode** top);
bool isOperator(char c);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

#endif /* EXPRESSION_TREE_H */
