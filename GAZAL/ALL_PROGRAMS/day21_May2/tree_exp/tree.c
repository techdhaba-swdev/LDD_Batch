#include "tree.h"
#include <stdlib.h>
#include <ctype.h>
struct Node {
    int data;
    char op; // Renamed from operator to op
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data, char op) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->op = op;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform in-order traversal and evaluate the expression
int evaluateExpression(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data; // Leaf node (operand)
    }
    // Evaluate left and right subtrees
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);
    // Perform operation based on operator
    switch (root->op) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0; // Invalid operator
    }
}


int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to build the binary tree from infix expression
struct Node* buildTree(char* expression) {
    struct Node* stack[100]; // Stack to hold operands and operators
    int top = -1; // Initialize stack top

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) { // Operand
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one position
            struct Node* node = createNode(operand, '\0'); // Create operand node
            stack[++top] = node; // Push operand onto stack
        } else if (expression[i] == '(') { // Left parenthesis
            struct Node* node = createNode(0, '('); // Create left parenthesis node
            stack[++top] = node; // Push left parenthesis onto stack
        } else if (expression[i] == ')') { // Right parenthesis
            while (top > 0 && stack[top]->op != '(') { // Pop until corresponding '(' is found
                struct Node* right = stack[top--]; // Pop right operand
                struct Node* op = stack[top--]; // Pop operator
                struct Node* left = stack[top--]; // Pop left operand
                op->left = left;
                op->right = right;
                stack[++top] = op; // Push subtree onto stack
            }
            top--; // Pop '(' from stack
        } else if (isOperator(expression[i])) { // Operator
            while (top > 0 && precedence(stack[top]->op) >= precedence(expression[i])) {
                struct Node* right = stack[top--]; // Pop right operand
                struct Node* op = stack[top--]; // Pop operator
                struct Node* left = stack[top--]; // Pop left operand
                op->left = left;
                op->right = right;
                stack[++top] = op; // Push subtree onto stack
            }
            struct Node* node = createNode(0, expression[i]); // Create operator node
            stack[++top] = node; // Push operator onto stack
        }
    }

    // Process remaining nodes on stack
    while (top > 0) {
        struct Node* right = stack[top--]; // Pop right operand
        struct Node* op = stack[top--]; // Pop operator
        struct Node* left = stack[top--]; // Pop left operand
        op->left = left;
        op->right = right;
        stack[++top] = op; // Push subtree onto stack
    }

    // The root of the expression tree is the top element of the stack
    return stack[0];
}