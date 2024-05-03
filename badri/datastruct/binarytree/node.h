#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    char operator;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value, char op);
struct Node* buildTree(char* expression);
int evaluateExpression(struct Node* root);

#endif
