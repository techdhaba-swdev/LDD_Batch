#include <stdio.h>
#include "binary_tree.h"

int main() {
    char expression[100];

    printf("Enter infix expression: ");
    scanf("%s", expression);


    struct TreeNode* root = buildTree(expression);

    printf("Result: %d\n", evaluateExpression(root));

    return 0;
}
