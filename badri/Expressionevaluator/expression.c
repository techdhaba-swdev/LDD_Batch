#include <stdlib.h> // Include standard library for memory allocation.
#include<stdio.h> // Include standard input-output library.
#include "node.h" // Include header file for Node structure and function prototypes.

struct Node* createNode(int value, char op) { // Define a function to create a new Node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new Node.
    if (newNode == NULL) { // Check if memory allocation fails.
        printf("Memory allocation failed!"); // Print error message.
        exit(1); // Terminate program.
    }
    newNode->data = value; // Assign value to data field of the Node.
    newNode->operator = op; // Assign operator to operator field of the Node.
    newNode->left = NULL; // Initialize left child pointer to NULL.
    newNode->right = NULL; // Initialize right child pointer to NULL.
    return newNode; // Return the newly created Node.
}

struct Node* buildTree(char* expression) { // Define a function to build expression tree from postfix expression.
    struct Node* stack[100]; // Declare a stack to hold Node pointers.
    int top = -1; // Initialize top of stack to -1.
    struct Node *t, *t1, *t2; // Declare Node pointers for tree construction.

    for (int i = 0; expression[i] != '\0'; i++) { // Iterate through each character of the expression.
        if (expression[i] >= '0' && expression[i] <= '9') { // If character is a digit.
            int num = 0; // Initialize variable to store number.
            while (expression[i] != ' ' && expression[i] != '\0') { // Loop to extract complete number.
                num = num * 10 + (expression[i] - '0'); // Convert character to integer and accumulate number.
                i++; // Move to next character.
            }
            i--; // Move back one position to account for extra increment in loop.
            t = createNode(num, '\0'); // Create a Node with the extracted number.
            stack[++top] = t; // Push the Node onto the stack.
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') { // If character is an operator.
            t = createNode(0, expression[i]); // Create a Node for the operator.
            t1 = stack[top--]; // Pop the top Node from stack as right child.
            t2 = stack[top--]; // Pop the next Node from stack as left child.
            t->right = t1; // Assign right child.
            t->left = t2; // Assign left child.
            stack[++top] = t; // Push the constructed subtree back onto the stack.
        }
    }
    return stack[top]; // Return the root of the expression tree.
}

int evaluateExpression(struct Node* root) { // Define a function to evaluate the expression tree.
    if (root == NULL) // If root is NULL, return 0.
        return 0;
    if (root->left == NULL && root->right == NULL) // If root is a leaf node, return its data.
        return root->data;
    
    int left_val = evaluateExpression(root->left); // Recursively evaluate left subtree.
    int right_val = evaluateExpression(root->right); // Recursively evaluate right subtree.

    switch (root->operator) { // Perform operation based on operator.
        case '+':
            return left_val + right_val;
        case '-':
            return left_val - right_val;
        case '*':
            return left_val * right_val;
        case '/':
            if (right_val == 0) // Division by zero check.
                return INT_MAX; // Return maximum integer value to indicate error.
            else
                return left_val / right_val;
        default:
            return 0; // Default case (should not be reached).
    }
}
