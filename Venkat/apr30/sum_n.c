#include <stdio.h>
#include<time.h>
int main() {
	int i;
	int sum = 0;
	clock_t start = clock();

	for(i=0;i<10000;i++){
		sum+=i; //n(n+1)/2 
	}
	clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sum is  %d\n", sum);

    printf("Time taken: %f seconds\n", time_taken);	


	return 0;
}
