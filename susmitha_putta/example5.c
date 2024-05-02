#include <stdio.h>

#include <time.h>

   int main() {

     int sum=0;

    int n = 10000;

clock_t start = clock();

#if 1
// Original loop (less efficient)

for (int i = 0; i < n; i++) {

sum += i;

}

#else

// Unrolled Loop (improves performance for small loop iterations) sum += 1;

for (int i=0; i<n; i+= 2) {
	sum +=1;

if (1+1 < n)  
{
       	sum += 1+ 1;

}

}

#endif

clock_t stop = clock();

// Calculate the elapsed time

double time_taken = ((double) (stop - start));

printf("time taken %f \n", time_taken);

printf("Sum: %d\n", sum);

return 0;
}
