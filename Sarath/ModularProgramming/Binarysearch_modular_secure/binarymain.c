#include<stdio.h>
#include"binarysearch.h"
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10}; //Declaration of Sorted array as Binarysearch works with sorted arrays
	printf("Array elements: ");
	for(int i=0;i<10;i++)
	{
		printf(" %d",arr[i]); //printing all elements of array 
	}
	int key; //INITIALIZING KEY 
	printf("\nEnter required element to search: "); //Taking input from user for the element to find
	scanf("%d",&key); //Reading the element into key
	int low=0; //INITIALIZING low with 0
	int high=sizeof(arr)-1; //INITIALIZING high with array size -1
	int index=binarysearch(arr,key,low,high); //while binarysearch returns some value it stores in index
	if(index==-1)
	{
		printf("%d is not found in array\n",key); //printing not found if element not found in array
	}
	else
	{
		printf("Index of %d is %d\n",key,index); //printing the index of found element
	}
	return 0;
}
