#include<stdio.h>
#include"postfix_stack.h"
// Main function
int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}


