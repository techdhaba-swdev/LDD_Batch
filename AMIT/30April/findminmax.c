#include<stdio.h>
#include<time.h>
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
	 clock_t start = clock();
	int arr[]={45,7,31,9,5,10};
	int size= sizeof(arr)/sizeof(arr[0]);

	findminmax(arr,size);
	clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

	return 0;
}
