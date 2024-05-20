// getPrecedence.c

#include "getPrecedence.h"

// Function to get the precedence of an operator in an expression.
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lower precedence for addition and subtraction.
        case '*':
        case '/':
            return 2; // Higher precedence for multiplication and division.
        default:
            return -1; // Return -1 for invalid operators.
    }
}


