#include <stdio.h>
#include "node.h"

int main() {
    char expression[] = " 2  3 4 + *";
    struct Node* root = buildTree(expression);
    int result = evaluateExpression(root);
    printf("Result: %d\n", result);
    return 0;
}
