#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binarysearch.h"
// Structure definition for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build a binary expression tree from infix expression
struct Node* buildExpressionTree(char* expression) {
    struct Node* stack[100];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
       
        if (isdigit(expression[i])) {
            struct Node* newNode = createNode(expression[i]);
            stack[++top] = newNode;
        }
        // If current character is an operator
        else if (isOperator(expression[i])) {
            // Create a new node for the operator
            struct Node* newNode = createNode(expression[i]);
            // Pop two operands from stack
            struct Node* rightOperand = stack[top--];
            struct Node* leftOperand = stack[top--];
            // Set the operands as children of the operator
            newNode->left = leftOperand;
            newNode->right = rightOperand;
            // Push the operator node onto the stack
            stack[++top] = newNode;
        }
    }

    // The root of the expression tree is at the top of the stack
    return stack[top];
}

// Function to evaluate the expression recursively
int evaluateExpression(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // If the node is an operand, return its value
    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    // Otherwise, recursively evaluate left and right subtrees
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    // Perform the operation based on the operator
    switch (root->data) {
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

// Main function
int main() {
    // Example infix expression: "2+3*4"
    char expression[] = "2+3*4";

    // Build the expression tree
    struct Node* root = buildExpressionTree(expression);

    // Evaluate the expression and print the result
    int result = evaluateExpression(root);
    printf("Result: %d\n", result);

    return 0;
}


