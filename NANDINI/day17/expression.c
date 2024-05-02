#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Define a structure for a binary tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

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
    // Stack to store tree nodes
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = 0; expression[i]; i++) {
        // If current character is an operand, create a node for it and push onto stack
        if (isdigit(expression[i])) {
            struct TreeNode* node = createNode(expression[i]);
            stack[++top] = node;
        }
        // If current character is an operator, create a node for it and
        // set its left and right children to the top two nodes in the stack
        else if (isOperator(expression[i])) {
            struct TreeNode* node = createNode(expression[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    // Return the root of the binary tree
    return stack[top];
}

// Function to perform an in-order traversal of the tree and evaluate the expression
int evaluateExpression(struct TreeNode* root) {
    // Base case: if root is NULL, return 0
    if (root == NULL) {
        return 0;
    }
    // If current node is an operand, return its value
    if (!isOperator(root->data)) {
        return root->data - '0';
    }
    // Evaluate left and right subtrees recursively
    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);
    // Perform the operation based on the operator
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

int main() {
    // Input infix expression string
    char expression[100];
    printf("Enter infix expression: ");
    scanf("%s", expression);

    // Build binary tree from infix expression
    struct TreeNode* root = buildTree(expression);

    // Evaluate expression and print result
    printf("Result: %d\n", evaluateExpression(root));

    return 0;
}
