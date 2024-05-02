#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {
    char expression[] = "2+3*4+3";
    TreeNode* root = buildTree(expression);

    printf("Infix expression: ");
    inOrderTraversal(root);
    printf("\n");

    int result = evaluate(root);
    printf("Result: %d\n", result);

    return 0;
}
