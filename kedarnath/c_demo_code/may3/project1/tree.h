// tree.h

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

// Forward declarations
typedef struct StackNode StackNode;
typedef struct Stack Stack;

// Function prototypes
Stack* createStack();
void push(Stack* stack, char data);
char pop(Stack* stack);
char peek(Stack* stack);
int isEmpty(Stack* stack);
int isOperand(char ch);
int precedence(char ch);
char* infixToPostfix(char* expression);
int evaluatePostfix(char* postfix);

#endif /* TREE_H */




