#include <stdio.h>
int main()
{
	int arr[] = {10,20,30,40};
	int element = 30;
	int size = sizeof(arr)/sizeof(arr[0]);
	for (int i =0 ; i<size ; i++)
	{
		if ( arr[i] == element)
		{
			
			printf("element found %d\n",arr[i]);
			break;
		}
		if(!element)
		{
			printf("element nott found");
		}
            

	}
}
