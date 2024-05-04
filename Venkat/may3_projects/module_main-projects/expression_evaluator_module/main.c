// main.c
#include <string.h>
#include "convertToPostfix.h"
#include "evaluatePostfix.h"
#include <stdio.h>
#include <time.h>

#define MAX_EXPR_LEN 100

int main() { 
    clock_t start = clock();
    char infix[MAX_EXPR_LEN];
    char postfix[MAX_EXPR_LEN];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_EXPR_LEN, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    convertToPostfix(infix, postfix); // Convert the infix expression to postfix
    printf("Postfix expression: %s\n", postfix); // Display the postfix expression

    int result = evaluatePostfix(postfix); // Evaluate the postfix expression
    printf("Result: %d\n", result); // Display the result of the evaluation
    // Stop the clock

    clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
