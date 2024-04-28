#include<stdio.h>
#include<math.h>


void insertSort(int arr[], int n)
{
	int i,key,j;

	for (i = 1;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i< n; i++)
	printf("%d,",arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {12,13,8,6,5};
	int n = sizeof(arr)/ sizeof(arr[0]);
	insertSort(arr,n);
	printArray(arr,n);
	return 0;
}
