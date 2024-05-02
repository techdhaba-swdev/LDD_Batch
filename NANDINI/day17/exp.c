#include "exp.h"
#include <stdlib.h>
#include <ctype.h>

// Function to create a new binary tree node with a given value
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator (+, -, *, /)
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build the binary tree from an infix expression string
struct TreeNode* buildTree(char* expression) {
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            struct TreeNode* node = createNode(expression[i]);
            stack[++top] = node;
        } else if (isOperator(expression[i])) {
            struct TreeNode* node = createNode(expression[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}

// Function to perform an in-order traversal of the tree and evaluate the expression
int evaluateExpression(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (!isOperator(root->data)) {
        return root->data - '0';
    }
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}
