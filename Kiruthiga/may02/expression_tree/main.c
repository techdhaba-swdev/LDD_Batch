#include<stdio.h>
#include"binarysearch.h"
// Main function
int main() {
    
    char expression[100];
    printf("enter infix expression:");
    scanf("%s",expression);

    // Build the expression tree
    struct Node* root = buildExpressionTree(expression);

    // Evaluate the expression and print the result
    int result = evaluateExpression(root);
    printf("Result: %d\n", result);

    return 0;
}

