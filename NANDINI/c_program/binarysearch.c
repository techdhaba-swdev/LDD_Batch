#include<stdio.h>
int binarysearch(int arr[], int i, int r, int x)
{
	while(i <= r)
	{
		int m = i+(r-i)/2;
				if(arr[m] ==x)
				return m;
				if(arr[m]<x)
				i=m+1;
				else
				r=m-1;
	
	}
return -1;
}
int main(void)
{
int arr[] = {7,10,22,29};
int n= sizeof(arr)/sizeof(arr[0]);
int x = 10;
int result = binarysearch(arr, 0, n-1, x);
(result == -1)? printf("element is not present" " in array"):printf("element is present at " "Index %d", result);
return 0;
}

