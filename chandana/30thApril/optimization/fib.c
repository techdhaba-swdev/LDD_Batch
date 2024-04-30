#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 20;
    clock_t start = clock();
    int result = fibonacci(n);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
