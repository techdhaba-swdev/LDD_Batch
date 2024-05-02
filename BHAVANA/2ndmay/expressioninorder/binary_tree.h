#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Define a structure for a binary tree node
struct TreeNode {
    char data;               // Data of the node (either an operand or an operator)
    struct TreeNode* left;   // Pointer to the left child node
    struct TreeNode* right;  // Pointer to the right child node
};

// Function prototypes
struct TreeNode* createNode(char data);      // Function to create a new binary tree node
struct TreeNode* buildExpressionTree(char* infix);  // Function to build the expression tree from infix expression
int evaluateExpression(struct TreeNode* root);      // Function to evaluate the expression using the binary tree

#endif /* BINARY_TREE_H */
