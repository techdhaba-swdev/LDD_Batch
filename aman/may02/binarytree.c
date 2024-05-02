#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binarytree.h"

// Function to create a new binary tree node
struct TreeNode* createNode(int is_operator, int value, char operator) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->is_operator = is_operator;
    newNode->value = value;
    newNode->operator = operator;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build binary tree from infix expression
struct TreeNode* buildTreeUtil(char* expression, int* index) {
    struct TreeNode* root = NULL;
    int operand = 0;
    int is_operator = 0;
    char operator;

    // Traverse through expression
    while (expression[*index]) {
        if (expression[*index] == '(') {
            (*index)++;
            root = buildTreeUtil(expression, index);
        }
        else if (isdigit(expression[*index])) {
            operand = 0;
            while (isdigit(expression[*index])) {
                operand = operand * 10 + (expression[*index] - '0');
                (*index)++;
            }
            root = createNode(0, operand, '\0'); // Operand node
        }
        else if (expression[*index] == '+' || expression[*index] == '-' || expression[*index] == '*' || expression[*index] == '/') {
            operator = expression[*index];
            is_operator = 1;
            (*index)++;
            root = createNode(1, 0, operator); // Operator node
            root->left = buildTreeUtil(expression, index);
            root->right = buildTreeUtil(expression, index);
        }
        else if (expression[*index] == ')') {
            (*index)++;
            return root;
        }
        else {
            (*index)++;
        }
    }
    return root;
}

struct TreeNode* buildTree(char* expression) {
    int index = 0;
    return buildTreeUtil(expression, &index);
}

// Function to evaluate expression using the binary tree
int evaluateExpression(struct TreeNode* root) {
    if (root->is_operator == 0) {
        return root->value; // Operand
    }
    int left = evaluateExpression(root->left);
    int right = evaluateExpression(root->right);
    switch (root->operator) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    default:
        return 0;
    }
}
