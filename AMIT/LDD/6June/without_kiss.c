#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2;
    char operator;
    
    printf("Welcome to the Advanced Calculator!\n");
    printf("Please enter an expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch (operator) {
        case '+':
            printf("The sum of %.2lf and %.2lf is %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("The difference between %.2lf and %.2lf is %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("The product of %.2lf and %.2lf is %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("The result of dividing %.2lf by %.2lf is %.2lf\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
             
            }
            break;
        default:
            printf("Invalid operator. Please use +, -, *, or /.\n");
         
    }
    
    printf("Thank you for using the Advanced Calculator!\n");
    return 0;
}

