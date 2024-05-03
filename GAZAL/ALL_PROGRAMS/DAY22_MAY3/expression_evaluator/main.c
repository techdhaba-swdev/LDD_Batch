#include <stdio.h> // Standard I/O library for input/output functions
#include <stdlib.h> // Standard library for memory allocation functions
#include <ctype.h> // Library for character handling functions
#include <time.h>// for adding clock
#include "main.h" // Include the header file for expression evaluation which we declare in main.h

int main() {
    clock_t start = clock();//optimization:clock start for knowing time taken by program
    char infix[100]; // Array to store the input infix expression
    printf("Enter infix expression: "); // Prompt the user to enter an infix expression
    scanf("%s", infix); // Read the infix expression from the user

    char postfix[100]; // Array to store the converted postfix expression
    infixToPostfix(infix, postfix); // Convert the infix expression to postfix
    printf("Postfix expression: %s\n", postfix); // Print the postfix expression

    int result = evaluatePostfix(postfix); // Evaluate the postfix expression
    printf("Result: %d\n", result); // Print the result of the expression evaluation
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time Taken : %f seconds\n", time_taken);

    return 0; // Return 0 to indicate successful completion of the program
}
