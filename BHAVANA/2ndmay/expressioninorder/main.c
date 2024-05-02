#include <stdio.h>
#include "binary_tree.h"

int main() {
    // Example infix expression
    char infix[] = "2+3*4";

    // Build the expression tree from the infix expression
    struct TreeNode* root = buildExpressionTree(infix);

    // Evaluate the expression by performing in-order traversal
    int result = evaluateExpression(root);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}
