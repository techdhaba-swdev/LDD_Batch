#include<stdio.h>
int main()
{
	int arr[] = {10, 5, 22, 7, 29};
	int n = sizeof(arr) / sizeof(arr[0]);
	int min = arr[0];
	int max = arr[0];
	for(int i = 1; i < n; i++)
{
	if (arr[i] < min)
	{
		min  = arr[i];
	}
	if (arr[i] > max)
	{
		max = arr[i];
	}
}
printf("smallest number: %d\n", min);
printf("biggest number: %d\n", max);
return 0;
}

