#include "expression_evaluator.h"  // Include header for expression evaluation functions (assumed)
#include <stdio.h>                   // Include standard input/output header
#include <time.h>                    // Include time header for clock function

#define MAX_EXPR_SIZE 100            // Define maximum expression size (constant)

int main() {
    char infix[MAX_EXPR_SIZE];       // Declare character array to store infix expression
    char postfix[MAX_EXPR_SIZE];      // Declare character array to store postfix expression
    double start_time, end_time;      // Declare variables to store start and end times

    // Get start time before expression evaluation
    start_time = clock();            // Get starting CPU time in clock ticks

    printf("Enter an infix expression: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);  // Read infix expression from user input

    infix_to_postfix(infix, postfix);  // Convert infix to postfix expression (assuming function exists)
    printf("Postfix expression: %s\n", postfix);  // Print converted postfix expression

    int result = evaluate_postfix(postfix);  // Evaluate postfix expression (assuming function exists)
    printf("Result: %d\n", result);          // Print evaluation result

    // Get end time after expression evaluation
    end_time = clock();                // Get ending CPU time in clock ticks

    // Calculate elapsed time in seconds
    double elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.6f seconds\n", elapsed_time);  // Print elapsed time with 6 decimal places

    return 0;
}