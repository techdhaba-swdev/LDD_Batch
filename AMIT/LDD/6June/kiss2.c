
#include <stdio.h>

int main() {
    double num1, num2;
    char operator;
    
    printf("Enter an expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch (operator) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case '/':
            printf("Result: %.2lf\n", num1 / num2);
            break;
        default:
            printf("Invalid operator.\n");
    }
    
    return 0;
}


