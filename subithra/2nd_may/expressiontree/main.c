#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

int main() {
    char expression[100];
    printf("Enter infix expression: ");
    fgets(expression, sizeof(expression), stdin); // Read input using fgets

    // Remove trailing newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    // Validate expression length
    if (strlen(expression) == 0) {
        printf("Error: Expression cannot be empty\n");
        return EXIT_FAILURE;
    }

    // Validate expression characters
    for (int i = 0; expression[i] != '\0'; i++) {
        if (!isdigit(expression[i]) && !isOperator(expression[i]) && expression[i] != '(' && expression[i] != ')') {
            printf("Error: Invalid character in expression\n");
            return EXIT_FAILURE;
        }
    }

    // Build the binary tree from the infix expression
    struct Node* root = buildTree(expression);

    // Check if root is NULL (failure in building tree)
    if (root == NULL) {
        printf("Error: Failed to build expression tree\n");
        return EXIT_FAILURE;
    }

    // Evaluate the expression and print the result
    int result = evaluateExpression(root);
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}