#ifndef EXP_EVALUATOR_H // Header guard to prevent multiple inclusion of the header file
#define EXP_EVALUATOR_H

// Forward declaration of struct StackNode to avoid circular dependency
struct StackNode;

// Function prototypes for stack operations
void push(struct StackNode** top, int data); // Push data onto the stack
int pop(struct StackNode** top); // Pop data from the stack
int peek(struct StackNode* top); // Peek at the top of the stack

// Function prototypes for expression evaluation
int isOperator(char c); // Check if a character is an operator
int precedence(char c); // Determine the precedence of an operator
void infixToPostfix(char* infix, char* postfix); // Convert infix expression to postfix
int evaluatePostfix(char* postfix); // Evaluate postfix expression

#endif /* EXP_EVALUATOR_H */ // End of header guard