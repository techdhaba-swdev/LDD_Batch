#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

// Define a Node in the stack
typedef struct Node {
    int data; // Store operand or operator as integer
    struct Node* next; // Pointer to the next node in the stack
} Node;

// Define a Stack
typedef struct Stack {
    Node* top; // Pointer to the top node in the stack
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Allocate memory for the stack
    if (stack == NULL) {
        printf("Error: Memory not allocated for stack\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    stack->top = NULL; // Initialize top pointer as NULL
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Error: Memory not allocated for new node\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    newNode->data = data; // Set the data of the new node
    newNode->next = stack->top; // Link the new node to the top of the stack
    stack->top = newNode; // Update the top pointer
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE); // Exit if the stack is empty
    }
    Node* temp = stack->top; // Temporary pointer to the top node
    int data = temp->data; // Retrieve data from the top node
    stack->top = stack->top->next; // Update the top pointer
    free(temp); // Free the memory of the popped node
    return data; // Return the popped data
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL; // Return true if the top pointer is NULL
}

// Function to get the precedence of operators
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lower precedence for addition and subtraction
        case '*':
        case '/':
            return 2; // Higher precedence for multiplication and division
        default:
            return -1; // Return -1 for invalid operators
    }
}

// Function to convert infix expression to postfix notation
void convertToPostfix(char infix[], char postfix[]) {
    Stack* stack = createStack(); // Create a new stack
    int j = 0; // Index for postfix array
    int i = 0; // Index for infix array

    // Loop through each character in the infix expression
    while (infix[i] != '\0') {
        char c = infix[i];

        // If the character is a digit, add it to the postfix expression
        if (isdigit(c)) {
            // Handle multi-digit numbers
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Add space for readability
        } else if (c == '(') {
            push(stack, c); // Push opening parenthesis onto the stack
            i++;
        } else if (c == ')') {
            // Pop operators from the stack until an opening parenthesis is encountered
            while (!isEmpty(stack) && stack->top->data != '(') {
                postfix[j++] = pop(stack);
                postfix[j++] = ' '; // Add space for readability
            }
            if (!isEmpty(stack) && stack->top->data == '(') {
                pop(stack); // Remove the opening parenthesis
            }
            i++;
        } else if (getPrecedence(c) > 0) {
            // Pop operators with higher or equal precedence from the stack
            while (!isEmpty(stack) && getPrecedence(stack->top->data) >= getPrecedence(c)) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' '; // Add space for readability
            }
            push(stack, c); // Push the current operator onto the stack
            i++;
        } else {
            i++; // Ignore any other characters
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' '; // Add space for readability
    }

    postfix[j] = '\0'; // Null-terminate the string
    free(stack); // Free the stack memory after conversion
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    Stack* stack = createStack(); // Create a new stack
    char *token = strtok(postfix, " "); // Tokenize the postfix expression

    // Loop through each token in the postfix expression
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(stack, atoi(token)); // Push operand onto the stack
        } else {
            int operand2 = pop(stack); // Pop the second operand
            int operand1 = pop(stack); // Pop the first operand
            int result;

            // Perform the operation based on the operator
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE); // Exit if division by zero is attempted
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator %c\n", token[0]);
                    exit(EXIT_FAILURE); // Exit if an invalid operator is encountered
            }
            push(stack, result); // Push the result back onto the stack
        }
        token = strtok(NULL, " "); // Get the next token
    }

    int finalResult = pop(stack); // Pop the final result
    if (!isEmpty(stack)) {
        printf("Error: Stack not empty after evaluation\n");
        exit(EXIT_FAILURE); // Exit if the stack is not empty after evaluation
    }

    free(stack); // Free the stack memory
    return finalResult; // Return the final result of the expression
}

// Main function to run the expression evaluator
int main() {
    char infix[MAX_EXPR_LEN]; // Array to store the infix expression
    char postfix[MAX_EXPR_LEN]; // Array to store the postfix expression

    printf("Enter an infix expression: ");
    fgets(infix, MAX_EXPR_LEN, stdin); // Read the infix expression from the user
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    convertToPostfix(infix, postfix); // Convert infix to postfix
    printf("Postfix expression: %s\n", postfix); // Print the postfix expression

    int result = evaluatePostfix(postfix); // Evaluate the postfix expression
    printf("Result: %d\n", result); // Print the result

    return 0; // Return success
}
