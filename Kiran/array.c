#include<stdio.h>

int printArray(int arr[], int n,int i)
{
	if(n == i)
	{
		return 0;
	}
	printf("%d\n",arr[i]);
	 printArray(arr, n , i+1);
}
int main()
{
   int arr[] = { 2, 14,88,34,20,45};
   int size = sizeof(arr)/sizeof(arr[0]);

   printf("Array Elements:");
   printArray(arr, size,0);
}
