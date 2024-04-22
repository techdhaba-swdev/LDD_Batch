
#include<stdio.h>
#include<math.h>
#define min(x,y) ((x)<(y)?(x):(y)) 
int jumpsearch(int arr[], int n, int k)
{
	int t=0;
	int b = (int)sqrt(n);
	while(arr[min(b,n)-1] < k)
	{
		t=b;
		b= b+(int)sqrt(n);
		if(t >= n)
		     	return -1;
	}
	while(arr[t] < k)
	{
		t = t+1;
		if (t == min(b,n))
			return -1;

		if(arr[t] == k)
			return t;
		
	}
}

	int main()
	{
		int arr[] = {3,5,7,9,11,15};
		int n = sizeof(arr)/sizeof(arr[0]);
		int k=9;
		int result = jumpsearch(arr, n, k);
		if(result != -1)
		printf("element found at the position %d/n", result);
		else
			printf("element not founf in array\n");
		return 0;
	}



