#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
// Structure definition for a binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(char data);
struct Node* buildExpressionTree(char* expression);
int evaluateExpression(struct Node* root);
#endif
