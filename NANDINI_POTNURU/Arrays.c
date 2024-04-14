#include<stdio.h>
#define MAX_SIZE 100
void printarray(int arr[], int start, int len);
int main()
{
	int arr[MAX_SIZE];
	int N, i;
	printf("Enter size of array:");
	scanf("%d", &N);
	printf("Enter elements in array:");
	for(i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Elements in array is: ");
	printarray(arr, 0, N);
	return 0;
}
void printarray(int arr[], int start, int len)
{
	if(start >= len)
		return;
	printf("%d, ", arr[start]);
	printarray( arr, start+1, len);
}


