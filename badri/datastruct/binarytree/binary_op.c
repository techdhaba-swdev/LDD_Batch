#include <stdlib.h>
#include<stdio.h>
#include "node.h"

struct Node* createNode(int value, char op) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = value;
    newNode->operator = op;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(char* expression) {
    struct Node* stack[100]; // Assuming maximum 100 elements in the stack
    int top = -1;
    struct Node *t, *t1, *t2;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            int num = 0;
            while (expression[i] != ' ' && expression[i] != '\0') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            t = createNode(num, '\0');
            stack[++top] = t;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            t = createNode(0, expression[i]);
            t1 = stack[top--];
            t2 = stack[top--];
            t->right = t1;
            t->left = t2;
            stack[++top] = t;
        }
    }
    return stack[top];
}

int evaluateExpression(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    
    int left_val = evaluateExpression(root->left);
    int right_val = evaluateExpression(root->right);

    switch (root->operator) {
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            return left_val / right_val;
        default:
            return 0;
    }
}
