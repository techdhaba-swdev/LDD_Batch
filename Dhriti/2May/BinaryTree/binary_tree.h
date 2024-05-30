#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

// Define a structure for a binary tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
struct TreeNode* createNode(char data);
bool isOperator(char c);
struct TreeNode* buildTree(char* expression);
int evaluateExpression(struct TreeNode* root);

#endif 