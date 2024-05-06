#include <stdio.h>
#include <stdlib.h>
#include "evaluator.h"
#include<string.h>
#include<time.h>
int main() { 
    clock_t start = clock();
    char infix[100];
    printf("Enter infix expression: ");
    fgets(infix, 100, stdin);

    if (infix[strlen(infix) - 1] == '\n')
        infix[strlen(infix) - 1] = '\0';

    char* postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start));
    printf("Time taken: %f\n", time_taken);
    free(postfix);
    return 0;
}
