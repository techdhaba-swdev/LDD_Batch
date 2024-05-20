#include <stdio.h>
#include <time.h>

// Function to calculate factorial iteratively
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Start the clock
    clock_t start = clock();

    // Calculate the factorial of 20
    int number = 20;
    unsigned long long fact = factorial(number);

    // Stop the clock
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the factorial and the execution time
    printf("Factorial of %d: %llu\n", number, fact);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
