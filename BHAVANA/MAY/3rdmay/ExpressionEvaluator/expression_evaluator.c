#include "stack.h"  // Include header file for stack operations (assumed)
#include <ctype.h>  // Include header for character classification functions
#include <stdio.h>  // Include standard input/output header

// Function to check if character is an operator
int is_operator(char c) {
    // Check if the character is one of the common arithmetic operators
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to get precedence of operator
int precedence(char c) {
    // Assign precedence levels based on operator type
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0; // Parentheses have highest precedence (convention)
    }
}

// Function to convert infix expression to postfix
void infix_to_postfix(char* infix, char* postfix) {
    Stack stack;  // Declare a stack object for operator manipulation
    stack.top = NULL;  // Initialize stack to be empty (top pointer points to NULL)

    int i = 0, j = 0;  // Indexes for infix and postfix strings

    while (infix[i] != '\0') { // Loop until null terminator in infix string
        if (isdigit(infix[i])) {  // Check if current character is a digit
            postfix[j++] = infix[i++];  // Copy digit to postfix and increment both indexes
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);  // Push '(' onto the stack and increment index
        } else if (infix[i] == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                // Pop operators from stack until encountering '(' and append them to postfix
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard '(' from stack
            i++;  // Increment index after processing closing parenthesis
        } else if (is_operator(infix[i])) {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                // Pop operators with higher or equal precedence from stack and append to postfix
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);  // Push current operator onto the stack and increment index
        } else {
            // Ignore other characters like spaces (optional handling)
            i++;
        }
    }

    // Pop remaining operators from stack after processing infix string
    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Add null terminator to mark the end of the postfix string
}

// Function to evaluate postfix expression
int evaluate_postfix(char* postfix) {
    Stack stack;  // Declare a stack object for operand manipulation
    stack.top = NULL;  // Initialize stack to be empty

    int i = 0;  // Index for postfix string

    while (postfix[i] != '\0') { // Loop until null terminator in postfix string
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert digit character to integer value and push onto stack
        } else if (is_operator(postfix[i])) {
            int operand2 = pop(&stack);  // Pop the second operand from the stack
            int operand1 = pop(&stack);  // Pop the first operand from the stack
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);  // Perform addition and push result onto stack
                    break;
                case '-':
                    push(&stack, operand1 - operand2);  // Perform subtraction and push result onto stack
                    break;
                case '*':
                    push(&stack, operand1 * operand2);  // Perform multiplication and push result onto stack
                    break;
                case '/':
                    push(&stack, operand1 / operand2);  // Perform division and push result onto stack
                    break;
            }
        }
        i++;  // Increment index after processing the current character
    }

    return pop(&stack);  // The final element on the stack is the result of the expression
}
