#include <stdio.h>
#include <time.h>

int main() {
	//start the clock
	clock_t start=clock();

	//code whose time complexity you want to measure
	//for example lets calculate the sum of first 1000 numbers
	int sum =0;
	for(int i=1 ;i<=1000;i++)
	{
		sum+=i;
	}
	//stop the clock 
	clock_t end=clock();
	//calculate the elapsed time
	double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("sum of first 1000 numbers:%d\n",sum);
	printf("time taken : %fseconds\n",time_taken);

        //printf("sum %d\n",sum);
	return 0;
}
