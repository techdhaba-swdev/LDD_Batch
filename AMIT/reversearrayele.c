#include<stdio.h>

void reversearr(int arr[] , int size)
{
	int first=0;
	int last=size-1;
	while(first<last)
	{
		int temp;
		temp=arr[first];
		arr[first]=arr[last];
		arr[last]=temp;
		first++;
		last--;
	}
}
int main()
{
	int arr[]={10,11,12,13,14,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("original array:\n");
	for(int i=0;i<size;i++)
	
		printf("%d\n",arr[i]);
	reversearr(arr,size);

	printf("Reverse arrray:\n");

	for(int i=0; i<size;i++)
		printf("%d\n",arr[i]);
	return 0;
}


