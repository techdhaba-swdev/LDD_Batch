#include<stdio.h>

int main()
{
	int arr[]={10,23,14,50,60};
	int size=sizeof(arr)/sizeof(arr[0]);

	int find=50;
	for(int i=0;i<size;i++)
	{
		if(find==arr[i])
		{
			printf("Element %d found at index %d.",arr[i],i);
			break;
		}
	}
}
