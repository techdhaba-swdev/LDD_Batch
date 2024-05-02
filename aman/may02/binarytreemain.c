#include <stdio.h>
#include "binarytree.h"

int main() {
    char expression[100];
    printf("Enter the infix expression: ");
    scanf("%s", expression);
    
    // Build binary tree from infix expression
    struct TreeNode* root = buildTree(expression);

    // Evaluate expression
    int result = evaluateExpression(root);

    // Print result
    printf("Result: %d\n", result);

    return 0;
}
