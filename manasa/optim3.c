#include <stdio.h>
#include <time.h>

// Less efficient version
void less_efficient() {
    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
}

// More efficient version
void more_efficient() {
    int sum = (999999 * 1000000) / 2; // Sum of arithmetic series formula
}

int main() {
    clock_t start, end;
    double less_efficient_time, more_efficient_time;

    // Time for less efficient version
    start = clock();
    less_efficient();
    end = clock();
    less_efficient_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Time for more efficient version
    start = clock();
    more_efficient();
    end = clock();
    more_efficient_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by less efficient version: %f seconds\n", less_efficient_time);
    printf("Time taken by more efficient version: %f seconds\n", more_efficient_time);

    return 0;
}

