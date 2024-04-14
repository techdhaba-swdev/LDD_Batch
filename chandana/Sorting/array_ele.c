#include <stdio.h>

void printArray(int arr[],int i,int n)
{
	if(i>=n)
	{
		return;
	}
	printf("%d ", arr[i]);
	printArray(arr,i+1,n);
}

int main()
{
	int arr[] ={1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf("Array elemets :");
	printArray(arr,0,n);

	return 0;
}
