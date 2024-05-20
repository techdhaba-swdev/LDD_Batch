#include <stdio.h>
#include <time.h>

#define MAX 100
unsigned long long factorial[MAX];

void initialize() {
    factorial[0] = 1;
    for (int i = 1; i < MAX; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

unsigned long long factorial_with_memoization(int n) {
    return factorial[n];
}

int main() {
    int num;
    clock_t start, end;
    double cpu_time_used;
    
    initialize(); // Pre-compute factorials
    printf("Enter a number to compute its factorial: ");
    scanf("%d", &num);
    
    start = clock();
    if (num >= 0 && num < MAX) {
        printf("Factorial of %d is %llu\n", num, factorial_with_memoization(num));
    } else {
        printf("Factorial of %d is too large to compute with this optimization.\n", num);
    }
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}


