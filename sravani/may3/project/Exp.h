#ifndef EXPRESSION_EVALUATOR_H // Check if EXPRESSION_EVALUATOR_H hasn't been included yet
#define EXPRESSION_EVALUATOR_H // Define header guard to prevent multiple inclusions

// Function prototypes
void infix_to_postfix(char* infix, char* postfix); // Prototype for infix to postfix conversion function
int evaluate_postfix(char* postfix); // Prototype for postfix expression evaluation function

#endif /* EXPRESSION_EVALUATOR_H */
