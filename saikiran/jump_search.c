#include<math.h>
#include<stdio.h>
#define min(x,y)((x)>(y)?(x):(y))

int JumpSearch(int arr[],int n,int k)
{

	int t=0;int b=(int)sqrt(n);
	while(arr[min(b,n)-1]<k)
	{
		t=b;
		b= b+(int)sqrt(n);
		if(t >= n)
			return -1;
	}
	while(arr[t]< k)
	{
		t = t+1;
		if(t == min(b,n))
			return -1;
		if(arr[t] == k)
			return t;
	}
}
int main()
{
	int a[7] = {5,7,9,18,22,29};
	int k = 22;
	printf("element found at the position %d\n", JumpSearch(a,7,k));
	return 0;
}

