#include<stdio.h>
#include"selection.h"
int main()
{
	int arr[]={5,9,7,6,4,0,2,3,8,1};
	int length=10;
	printf("Unsorted Array: ");
	for(int i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nSorted Array:");
	selectionsortasc(arr,length);
	for(int i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	selectionsortdec(arr,length);
	for(int i=0;i<length;i++)
        {
                printf("%d ",arr[i]);
        }
	printf("\n");
	return 0;
}
