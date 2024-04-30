#include<stdio.h>
#include<time.h>
#define SIZE 5

int main() {

	clock_t start = clock(); //start the clock
	int arr[SIZE] ={1,2,3,4,5};
	int sum=0;


	for(int i=0; i<SIZE; i++) 
	{
		sum = sum + arr[i];
	
	}

	clock_t end = clock(); //stop the clock

        double time_taken = ((double)(end - start)); //cal the elapsed time'

	  printf("Time taken: %f seconds \n",time_taken);

	printf("Sum of the elements is : %d\n", sum);

	return 0;
}

