#include<stdio.h>

int linearsearch(int arr[] , int size, int searchelement)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==searchelement)
			return i;
	}

	return -1;
}
 
int main()
{
	int arr[]={10,20,30,40,50,60};
	int size= sizeof(arr)/sizeof(arr[0]);

	int searchelement= 30;

	int result= linearsearch(arr,size,searchelement);

	if(result!= -1)
	   printf("Element %d  found at the index %d \n",searchelement,result);
	else
	printf("Element %d not found in the array\n",searchelement);
return 0;
}

