#include <stdio.h>

// Function to calculate sum
int calculateSum(int a, int b) {
    return a + b;
}

// Function to calculate product
int calculateProduct(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;
    
    // Input first number
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    // Input second number
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Calculate and print sum
    int sum = calculateSum(num1, num2);
    printf("Sum: %d\n", sum);
    
    // Calculate and print product
    int product = calculateProduct(num1, num2);
    printf("Product: %d\n", product);
    
    return 0;
}


