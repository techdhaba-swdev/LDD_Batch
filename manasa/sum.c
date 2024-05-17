#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    // Input the numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Add the numbers
    sum = num1 + num2;
    
    // Display the result
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    
    return 0;
}
