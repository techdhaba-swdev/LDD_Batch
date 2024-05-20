// convertToPostfix.c

#include "convertToPostfix.h"
#include "createStack.h"
#include "getPrecedence.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "push.h"
#include "pop.h"
#include "isEmpty.h"
// Function to convert infix expression to postfix notation
void convertToPostfix(char infix[], char postfix[]) {
    Stack* stack = createStack(); // Create a stack to hold operators
    int j = 0; // Index for postfix array
    int i = 0; // Index for infix array

    // Iterate over the infix expression
    while (infix[i] != '\0') {
        char c = infix[i];

        // If the character is a digit, append it to postfix expression
        if (isdigit(c)) {
            // Handle multi-digit numbers
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add space to separate numbers
        } else if (c == '(') {
            // Push '(' onto stack
            push(stack, c);
            i++;
        } else if (c == ')') {
            // Pop operators from stack until '(' is encountered
            while (!isEmpty(stack) && stack->top->data != '(') {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            pop(stack); // Pop the '(' from stack
            i++;
        } else if (getPrecedence(c) > 0) {
            // Pop operators with higher or equal precedence
            while (!isEmpty(stack) && getPrecedence(stack->top->data) >= getPrecedence(c)) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            push(stack, c); // Push current operator onto stack
            i++;
        } else {
            i++; // Ignore any other characters
        }
    }

    // Pop any remaining operators from stack to postfix expression
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
    free(stack); // Free the stack memory
}
