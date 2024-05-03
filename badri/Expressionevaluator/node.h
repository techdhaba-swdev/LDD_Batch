#ifndef NODE_H // Header guard to prevent multiple inclusion of the header file.
#define NODE_H

struct Node { // Definition of a structure representing a node in the expression tree.
    int data; // Data stored in the node.
    char operator; // Operator (if applicable) stored in the node.
    struct Node* left; // Pointer to the left child node.
    struct Node* right; // Pointer to the right child node.
};

struct Node* createNode(int value, char op); // Function prototype for creating a new node.
struct Node* buildTree(char* expression); // Function prototype for building an expression tree from a postfix expression.
int evaluateExpression(struct Node* root); // Function prototype for evaluating the expression tree.

#endif // End of header guard.
