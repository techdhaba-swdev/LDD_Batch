#include <stdio.h>

// Function to calculate the factorial recursively
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;
    // Recursive case: n! = n * (n-1)!
    else
        return n * factorial(n - 1);
}

// Main function to test the factorial function
int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(n);
        printf("Factorial of %d is %d\n", n, result);
    }
    return 0;
}
