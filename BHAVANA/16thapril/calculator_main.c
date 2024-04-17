#include <stdio.h>
#include "calculator.h"

int main() {
    int num1, num2;
    char op;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (op) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            if (num2 != 0) {
                printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0;
}
