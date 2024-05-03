#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"infix.h"
#include<time.h>

int main() 
{   

    clock_t start = clock();	
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char postfix[100];
    infixToPostfix(infix, postfix);

    double result = evaluatePostfix(postfix);
    printf("Result: %.2f\n", result);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
