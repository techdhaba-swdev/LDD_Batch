#include <stdio.h>

int main() {
    float num1, num2;
    char operation;

    printf("Enter number 1: ");
    scanf("%f", &num1);

    printf("Enter number 2: ");
    scanf("%f", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation); // note the space before %c to consume any leading whitespace

    switch(operation) {
        case '+':
            printf("Result: %.2f\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2f\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2f\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0) {
                printf("Result: %.2f\n", num1 / num2);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Error: Invalid operation\n");
    }

    return 0;
}
