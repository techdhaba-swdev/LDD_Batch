#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int n;
    printf("Enter the number");
    scanf("%d", &n);
    printf("Fibonacci Series %d \n", n);
    printFibonacci(n);
    return 0;
}
