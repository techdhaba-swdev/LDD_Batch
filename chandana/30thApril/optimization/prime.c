#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 9999991; // Large prime number
    clock_t start = clock();
    bool result = is_prime(n);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("%d %s a prime number\n", n, result ? "is" : "is not");
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
