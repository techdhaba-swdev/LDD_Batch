#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

// Structure definition for a node in the binary tree
struct Node ;

// Function prototypes
int precedence(char op);
struct Node* createNode(int data, char op); // Renamed parameter from operator to op
bool isOperator(char c);
int evaluateExpression(struct Node* root);
struct Node* buildTree(char* expression);

#endif /* TREE_H */