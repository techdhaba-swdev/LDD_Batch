#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binary_tree.h"

// Function to create a new binary tree node with a given value
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // Allocate memory for the new node
    if (newNode == NULL) {  // Check if memory allocation is successful
        fprintf(stderr, "Memory allocation failed\n"); // Print error message to stderr
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }
    newNode->data = data;   // Assign the data to the new node
    newNode->left = NULL;   // Initialize the left child pointer to NULL
    newNode->right = NULL;  // Initialize the right child pointer to NULL
    return newNode;         // Return the pointer to the new node
}

// Function to push a node onto the stack
void push(struct TreeNode** stack, int* top, struct TreeNode* node) {
    (*top)++;                    // Increment the top of the stack
    stack[*top] = node;          // Assign the node to the top of the stack
}

// Function to pop a node from the stack
struct TreeNode* pop(struct TreeNode** stack, int* top) {
    struct TreeNode* node = stack[*top];   // Get the node from the top of the stack
    (*top)--;                              // Decrement the top of the stack
    return node;                           // Return the popped node
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');  // Return true if the character is an operator
}

// Function to build the binary tree from a given infix expression string
struct TreeNode* buildExpressionTree(char* infix) {
    struct TreeNode* stack[100];  // Stack to hold operators and operands
    int top = -1;                  // Initialize top of stack to -1

    for (int i = 0; infix[i] != '\0'; i++) { // Loop through the infix expression
        if (isdigit(infix[i])) {  // If the character is a digit (operand)
            struct TreeNode* newNode = createNode(infix[i]); // Create a new node
            push(stack, &top, newNode); // Push the node onto the stack
        } else if (isOperator(infix[i])) { // If the character is an operator
            struct TreeNode* newNode = createNode(infix[i]); // Create a new node for the operator
            newNode->right = pop(stack, &top); // Set the right child of the operator node
            newNode->left = pop(stack, &top);  // Set the left child of the operator node
            push(stack, &top, newNode);  // Push the operator node onto the stack
        }
    }

    return pop(stack, &top);  // Return the root of the expression tree
}

// Function to perform in-order traversal of the tree and evaluate the expression
int evaluateExpression(struct TreeNode* root) {
    if (root == NULL) {  // If the root is NULL, return 0
        return 0;
    }
    // Evaluate left subtree
    int leftValue = evaluateExpression(root->left);

    // Evaluate current node (operator)
    int rightValue = evaluateExpression(root->right);
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
            return root->data - '0'; // Convert character to integer
    }
}
