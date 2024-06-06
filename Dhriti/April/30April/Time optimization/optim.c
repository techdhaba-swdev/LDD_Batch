#include<stdio.h>
#include<time.h>

int main () {
	clock_t start = clock(); //start the clock
	
	int n=10;
	int fact =1;
	for(int i=1;i<=n;i++) {
		fact *= i;
	}


	clock_t end = clock(); //stop the clock
        
	double time_taken = ((double)(end - start)); //cal the elapsed time'
						
	printf("Factorial: %d is %d\n", n, fact);
	printf("Time taken: %f seconds \n",time_taken);

	return 0;
}
