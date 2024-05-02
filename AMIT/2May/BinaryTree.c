#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a binary tree node
typedef struct Node {
    char data; // Can hold an integer value or an operator character
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new binary tree node with a given value
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform an in-order traversal and evaluate the expression
int evaluateExpression(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftValue = evaluateExpression(root->left);
    int rightValue = evaluateExpression(root->right);

    if (root->data == '+') {
        return leftValue + rightValue;
    } else if (root->data == '-') {
        return leftValue - rightValue;
    } else if (root->data == '*') {
        return leftValue * rightValue;
    } else if (root->data == '/') {
        return leftValue / rightValue;
    } else {
        // If the node holds an integer value, return it
        return root->data - '0';
    }
}

// Function to parse the infix expression string and build the binary tree
Node* parseExpression(char* expression) {
    // Base case: if the expression is empty, return NULL
    if (*expression == '\0') {
        return NULL;
    }

    // Create a new node for the current operand or operator
    Node* node = createNode(*expression);

    // If the current character is an operand (digit), move to the next character
    if (isdigit(*expression)) {
        expression++;
    }
    // If the current character is an operator, parse the left and right subtrees
    else if (strchr("+-*/", *expression) != NULL) {
        expression++; // Move past the operator
        node->left = parseExpression(expression);
        node->right = parseExpression(expression);
    }
    // If the current character is a left parenthesis, parse the subtree inside
    else if (*expression == '(') {
        expression++; // Move past the left parenthesis
        node->left = parseExpression(expression);
        expression++; // Move past the right parenthesis
    }

    return node;
}

int main() {
    char expression[] = "2+3*4";
    Node* root = parseExpression(expression);
    int result = evaluateExpression(root);
    printf("Result: %d\n", result);
    return 0;
}
