#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure for binary tree node
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build the expression tree from infix expression
Node* buildExpressionTree(char *exp) {
    int len = strlen(exp);
    Node *stack[len];
    int top = -1;

    Node *root = NULL;
    for (int i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            root = newNode(exp[i]);
            stack[++top] = root;
        } else if (isOperator(exp[i])) {
            root = newNode(exp[i]);
            root->right = stack[top--];
            root->left = stack[top--];
            stack[++top] = root;
        }
    }
    return stack[top];
}

// Function to perform in-order traversal and evaluate expression
int evaluateExpression(Node* root) {
    if (root == NULL)
        return 0;

    if (!isOperator(root->data))
        return root->data - '0';

    int left_val = evaluateExpression(root->left);
    int right_val = evaluateExpression(root->right);

    switch (root->data) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
    }
    return 0;
}

int main() {
    char exp[100];
    printf("Enter the infix expression: ");
    scanf("%s", exp);

    Node* root = buildExpressionTree(exp);

    printf("Result: %d\n", evaluateExpression(root));

    return 0;
}
