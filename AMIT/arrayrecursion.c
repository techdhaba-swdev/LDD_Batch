#include<stdio.h>

void printarr(int arr[],int size,int index)
{
	if(index>=size)
		return;
	
	printf("%d \n",arr[index]);
	printarr(arr, size,index+1);
}

int main()
{
	int arr[]={32,43,65,78,45};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Array Elemant:");
	printarr(arr,size,0);
	return 0;
}
