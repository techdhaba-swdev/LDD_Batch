#include <stdio.h>
#include <time.h>

int main() {

	int sum = 1;
	int n = 100000;
    // Start the clock
    clock_t start = clock();

 

    // Code whose time complexity you want to measure
    // For example, let's calculate the sum of first 1000 numbers
    
   /* for (int i = 0; i <= n; i++) {
        sum += i;
    }*/

    for(int i=0;i<n;i+=2){
	    sum +=i;
	    if(i+1<n){
		    sum +=i+1;
	    }
    }
 

    // Stop the clock
    clock_t end = clock();

 

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

 

    printf("Sum of first 1000 numbers: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);

 

    return 0;
}
