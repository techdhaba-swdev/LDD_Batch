#include<stdio.h>
#include"bubblesort.h"
int main()
{
	int arr[]={2,6,4,7,10,5,9,3,1,8};
	int length=10;
	printf("Unsorted array: ");
	for(int i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nSorted array :");
	bubblesort(arr,length);
	for(int i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	bubblesortdec(arr,length);
	for(int j=0;j<length;j++)
        {
                printf("%d ",arr[j]);
        }
	printf("\n");
	return 0;
}
