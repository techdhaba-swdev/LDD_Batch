#include"tree.h"

// Main function
int main() {

    clock_t start=clock();
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char* postfix = infixToPostfix(infix);
    if (postfix == NULL) {
        printf("Error: Invalid expression\n");
        return 1;
    }
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    if (result != -1)
        printf("Result: %d\n", result);
    free(postfix);
    clock_t end=clock();
    double time_taken=((double)(end-start));
    printf("time taken is %f\n",time_taken);
    return 0;
}


