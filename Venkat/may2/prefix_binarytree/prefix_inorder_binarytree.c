#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the binary tree node structure
typedef struct Node {
    union {
        int value; // for operands
        char op;   // for operators
    };
    struct Node *left, *right;
    int isOperator; // flag to indicate if the node is an operator
} Node;

// Function to create a new node with an integer value
Node* createValueNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->isOperator = 0;
    return newNode;
}

// Function to create a new node with an operator
Node* createOperatorNode(char op) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->op = op;
    newNode->left = newNode->right = NULL;
    newNode->isOperator = 1;
    return newNode;
}

//  Implement the function to build the binary tree from an infix expression string
// This will require parsing the string and using a stack to handle parentheses and operator precedence

// Function to evaluate the expression tree
int evaluate(Node* root) {
    if (root == NULL) return 0;
    if (!root->isOperator) return root->value;

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    switch (root->op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0;
    }
}

// Helper function to perform an in-order traversal and print the tree
void printInOrder(Node* root) {
    if (root == NULL) return;
    if (root->isOperator) printf("(");
    printInOrder(root->left);
    if (root->isOperator) printf(" %c ", root->op);
    else printf(" %d ", root->value);
    printInOrder(root->right);
    if (root->isOperator) printf(")");
}

// Main function
int main() {
    // Example usage:
    // Build the tree for the expression 2 + 3 * 4
    Node* root = createOperatorNode('+');
    root->left = createValueNode(2);
    root->right = createOperatorNode('*');
    root->right->left = createValueNode(3);
    root->right->right = createValueNode(4);

    // Print the in-order traversal of the tree
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Evaluate the expression
    printf("Evaluated result: %d\n", evaluate(root));


    return 0;
}
