#include <stdio.h>

int main() {
	int arr[] = {1,2,3,4,5};
	int n= sizeof(arr)/sizeof(arr[0]);
        
        printf("orginal elements:");	
	for(int i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}
	/*for(int i=0;i<n/2;i++)
	{
           int temp = arr[i];
	   arr[i]=arr[n-i-1];
	   arr[n-i-1]=temp;
	}*/
	printf("Reversed array : ");
	for(int i=n-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
