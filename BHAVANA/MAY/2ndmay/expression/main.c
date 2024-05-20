#include <stdio.h>
#include "expression_tree.h"

int main() {
    char infix[] = "2 + 3 * 4";
    char postfix[100];

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
