#include <stdio.h>

int main()
{
	int arr[]= {1,7,4,3,9,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=1;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
			{
				printf("key found %d\n",arr[i]);
				break;
			}
		else
		{
			printf("key not found");
		}

	}
}

