#include <stdio.h>
#include <stdbool.h>
#include<time.h>
int main() {
	  clock_t start = clock(); //start the clock
    int n = 17;
    bool isPrime = true;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

     clock_t end = clock(); //stop the clock

        double time_taken = ((double)(end - start)); //cal the elapsed time'

    if (isPrime) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

     printf("Time taken: %f seconds \n",time_taken);

    return 0;
}

