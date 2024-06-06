#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<string.h>
#include "eval.h"
#define MAX 100
int main() {
    clock_t start, end;
    double cpu_time_used;
    char infix[MAX], postfix[MAX];
    start=clock();
    // Input infix expression
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character from input
    infix[strcspn(infix, "\n")] = '\0';

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    // Measure time taken
    // Perform operations here...
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
