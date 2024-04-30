#include<stdio.h>

#define SIZE 5

int main() {
	int arr[SIZE] ={1,2,3,4,5};
	int sum=0;


	for(int i=0; i<SIZE; i++) 
	{
		sum = sum + arr[i];
	
	}

	printf("Sum of the elements is : %d\n", sum);

	return 0;
}
