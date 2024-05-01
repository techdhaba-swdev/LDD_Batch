#include<stdio.h>
#include<time.h>
int main(){
	clock_t start= clock();
	int i;
	int sum = 0;

	for(i=0;i<=10;i++){
		sum += i;
	}
	clock_t stop = clock();
	double time_taken = ((double)(stop- start));
	printf("time taken: %f\n", time_taken);
	printf("the sum is: %d\n", sum);
	return 0;
}
