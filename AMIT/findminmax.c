#include<stdio.h>
 void findminmax(int arr[],int size)
{
	int min=arr[0];
	int max=arr[0];

	for(int i=1;i<size;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}

	printf("Smallest element in the array is:%d\n",min);
	printf("largest element in the array is:%d\n", max);
}

int main()
{
	int arr[]={45,7,31,9,5,10};
	int size= sizeof(arr)/sizeof(arr[0]);

	findminmax(arr,size);

	return 0;
}
