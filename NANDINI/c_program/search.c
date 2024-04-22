#include<stdio.h>
int main()
{
	int arr[] = {22, 29, 7,30,10};
       int search = 29;
int size = sizeof(arr)/sizeof(int);
for(int i=0;i<size;i++)
{
	if(search == arr[i])
	{
		printf("element is found %d\n", arr[i]);
		break;
	}
}
return 0;
}


