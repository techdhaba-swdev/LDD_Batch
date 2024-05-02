#include <stdio.h>

#include <time.h>

int main() {

int sum = 0;

int n = 10000;

clock_t start = clock();

#if 0

// Original loop (less efficient)

for (int i = 0; i < n; i++) {

sum += 1;

}

#else

// Unrolled loop (improves performance for small loop iterations)

for (int i = 0; i < n; i+= 2) {

sum += i;

if (i + 1 < n) {

sum += i + 1;

}

#endif

clock_t stop = clock();

// Calculate the elapsed time

double time_taken = ((double)(stop - start));

printf("time taken %f \n", time_taken);

printf("Sum: %d\n", sum);

return 0;

}
}
