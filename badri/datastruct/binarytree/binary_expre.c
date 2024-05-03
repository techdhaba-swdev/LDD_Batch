#include "expression_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Helper function to convert a character digit to integer
int charToInt(char c) {
    return c - '0';
}

// Function to create a new node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // Allocate memory for the new node
    if (newNode == NULL) { // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n"); // Print error message
        exit(EXIT_FAILURE); // Exit program with failure status
    }
    newNode->data = data; // Assign data to the new node
    newNode->left = NULL; // Initialize left child pointer
    newNode->right = NULL; // Initialize right child pointer
    return newNode; // Return the new node
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Return true if character is an operator, false otherwise
}

// Function to build the binary tree from infix expression
TreeNode* buildTree(char* expression) {
    TreeNode* stack[100]; // Stack to hold operands and operators
    int top = -1; // Initialize top of stack

    printf("Expression: %s\n", expression); // Print the input expression

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) { // Check if current character is a digit (operand)
            TreeNode* operandNode = createNode(expression[i]); // Create a new node for the operand
            stack[++top] = operandNode; // Push the operand node onto the stack
            printf("Pushed operand: %c\n", expression[i]); // Print debug message
        }
        else if (isOperator(expression[i])) { // Check if current character is an operator
            TreeNode* operatorNode = createNode(expression[i]); // Create a new node for the operator
            operatorNode->right = stack[top--]; // Pop the top two nodes from the stack to be the children of the operator node
            operatorNode->left = stack[top--];
            stack[++top] = operatorNode; // Push the operator node onto the stack
            printf("Pushed operator: %c\n", expression[i]); // Print debug message
        }
    }
    // The root of the tree will be the only node left in the stack
    printf("Finished building tree\n"); // Print debug message
    return stack[top]; // Return the root of the tree
}

// Function to perform in-order traversal
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left); // Traverse left subtree
        printf("%c ", root->data); // Visit root node
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Function to evaluate the expression
int evaluate(TreeNode* root) {
    if (root == NULL) { // Check if tree is empty
        fprintf(stderr, "Error: Empty tree\n"); // Print error message
        exit(EXIT_FAILURE); // Exit program with failure status
    }
    if (!isOperator(root->data)) { // Check if current node is an operand
        return charToInt(root->data); // Return integer value of operand
    }
    // Evaluate left and right subtrees recursively and perform operation based on operator
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue == 0) { // Check for division by zero
                fprintf(stderr, "Error: Division by zero\n"); // Print error message
                exit(EXIT_FAILURE); // Exit program with failure status
            }
            return leftValue / rightValue;
        default:
            fprintf(stderr, "Error: Invalid operator\n"); // Print error message
            exit(EXIT_FAILURE); // Exit program with failure status
    }
}

// Function to free memory allocated for the tree
void freeTree(TreeNode* root) {
    if (root != NULL) { // Check if tree is not empty
        freeTree(root->left); // Free left subtree
        freeTree(root->right); // Free right subtree
        free(root); // Free current node
    }
}
