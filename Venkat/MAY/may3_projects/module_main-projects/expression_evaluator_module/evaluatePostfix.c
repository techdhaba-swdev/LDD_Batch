// evaluatePostfix.c 
#include <stdio.h>
#include "evaluatePostfix.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "createStack.h"
#include "push.h"
#include "pop.h"
#include "isEmpty.h"
// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    Stack* stack = createStack(); // Create a stack to hold operands
    char *token = strtok(postfix, " "); // Tokenize the postfix expression

    // Iterate over each token in the postfix expression
    while (token != NULL) {
        if (isdigit(token[0])) {
            // If token is an operand, push it onto the stack
            push(stack, atoi(token));
        } else {
            // If token is an operator, pop two operands, perform operation, and push result
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;

            switch (token[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator %c\n", token[0]);
                    exit(EXIT_FAILURE);
            }
            push(stack, result); // Push the result back onto the stack
        }
        token = strtok(NULL, " "); // Move to the next token
    }

    int finalResult = pop(stack); // Pop the final result from the stack

    if (!isEmpty(stack)) {
        printf("Error: Stack not empty after evaluation\n");
        exit(EXIT_FAILURE);
    }

    free(stack); // Free the stack memory
    return finalResult; // Return the final result of the expression
}
