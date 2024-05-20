// incluing the required header files 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
// main function
int main() {
    clock_t start, end;
    double cpu_time_used;
    //starting the clock timeoo

    start = clock();
    char infix[100], postfix[100];

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
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}