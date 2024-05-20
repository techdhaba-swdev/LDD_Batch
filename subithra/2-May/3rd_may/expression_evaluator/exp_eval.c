#include "exp_eval.h" // Include the header file for the expression evaluator
#include <stdlib.h> // Standard library for memory allocation functions
#include <stdio.h> // Standard I/O library for input/output functions
#include <ctype.h> // Library for character handling functions

// Define a structure for stack node
struct StackNode {
    int data; // Data of the node
    struct StackNode* next; // Pointer to the next node in the stack
}; // End of structure definition

void push(struct StackNode** top, int data) { // Function to push data onto the stack
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode)); // Allocate memory for a new node
    if (newNode == NULL) { // Check if memory allocation failed (security: memory safety)
        printf("Memory allocation error.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }
    newNode->data = data; // Set the data for the new node
    newNode->next = *top; // Link the new node to the top of the stack
    *top = newNode; // Update the top pointer to point to the new node
}

int pop(struct StackNode** top) { // Function to pop data from the stack
    if (*top == NULL) { // Check if the stack is empty (security: defensive programming)
        printf("Stack underflow.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }
    struct StackNode* temp = *top; // Create a temporary pointer to the top node
    int data = temp->data; // Get the data from the top node
    *top = (*top)->next; // Move the top pointer to the next node
    free(temp); // Free the memory of the popped node
    return data; // Return the popped data
}

int peek(struct StackNode* top) { // Function to peek at the top of the stack
    if (top == NULL) { // Check if the stack is empty (security: defensive programming)
        printf("Stack is empty.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }
    return top->data; // Return the data at the top of the stack
}

int isOperator(char c) { // Function to check if a character is an operator
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Return true if the character is an operator
}

int precedence(char c) { // Function to determine the precedence of an operator
    if (c == '+' || c == '-') // If the operator is addition or subtraction
        return 1; // Return precedence 1
    else if (c == '*' || c == '/') // If the operator is multiplication or division
        return 2; // Return precedence 2
    else
        return 0; // Return precedence 0 for other characters (security: fail-safe)
}

void infixToPostfix(char* infix, char* postfix) { // Function to convert infix expression to postfix
    struct StackNode* stack = NULL; // Initialize an empty stack
    int i = 0, j = 0; // Initialize counters for input and output strings

    while (infix[i] != '\0') { // Loop through the infix expression
        if (isdigit(infix[i])) { // If the character is a digit
            postfix[j++] = infix[i++]; // Copy the digit to the postfix expression
        } else if (isOperator(infix[i])) { // If the character is an operator
            while (stack != NULL && precedence(infix[i]) <= precedence(peek(stack))) { // While there are operators on the stack with higher or equal precedence
                postfix[j++] = pop(&stack); // Pop and copy operators from the stack to the postfix expression
            }
            push(&stack, infix[i++]); // Push the current operator onto the stack
        } else if (infix[i] == '(') { // If the character is an opening parenthesis
            push(&stack, infix[i++]); // Push the opening parenthesis onto the stack
        } else if (infix[i] == ')') { // If the character is a closing parenthesis
            while (stack != NULL && peek(stack) != '(') { // While there are operators on the stack and the top is not an opening parenthesis
                postfix[j++] = pop(&stack); // Pop and copy operators from the stack to the postfix expression
            }
            pop(&stack); // Discard the opening parenthesis
            i++; // Move to the next character
        } else {
            printf("Invalid character in expression.\n"); // Print error message for invalid character
            exit(EXIT_FAILURE); // Exit the program with failure status
        }
    }

    while (stack != NULL) { // While there are operators on the stack
        postfix[j++] = pop(&stack); // Pop and copy operators from the stack to the postfix expression
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int evaluatePostfix(char* postfix) { // Function to evaluate postfix expression
    struct StackNode* stack = NULL; // Initialize an empty stack
    int i = 0; // Initialize counter for input string

    while (postfix[i] != '\0') { // Loop through the postfix expression
        if (isdigit(postfix[i])) { // If the character is a digit
            push(&stack, postfix[i] - '0'); // Push the digit value onto the stack
        } else if (isOperator(postfix[i])) { // If the character is an operator
            int operand2 = pop(&stack); // Pop the second operand from the stack
            int operand1 = pop(&stack); // Pop the first operand from the stack
            switch (postfix[i]) { // Perform the operation based on the operator
                case '+':
                    push(&stack, operand1 + operand2); // Push the result of addition onto the stack
                    break;
                case '-':
                    push(&stack, operand1 - operand2); // Push the result of subtraction onto the stack
                    break;
                case '*':
                    push(&stack, operand1 * operand2); // Push the result of multiplication onto the stack
                    break;
                case '/':
                    push(&stack, operand1 / operand2); // Push the result of division onto the stack
                    break;
            }
        }
        i++; // Move to the next character in the postfix expression
    }

    return pop(&stack); // Return the result of the postfix expression
}