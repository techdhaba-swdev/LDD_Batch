#include <stdio.h> // Include standard input-output library.
#include "node.h" // Include header file for Node structure and function prototypes.

int main() { // Main function entry point.
    char expression[] = " 2  3 4 + *"; // Define postfix expression.
    struct Node* root = buildTree(expression); // Build expression tree from the expression.
    int result = evaluateExpression(root); // Evaluate the expression tree.
    printf("Result: %d\n", result); // Print the result.
    return 0; // Exit the program with success status.
}
