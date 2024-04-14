#include<stdio.h>

int print_out_end(int n)
{
	if(n<0)
	{
		return 1;
	}
	else
	{
		printf("value of n: %d\n",n);
		print_out_end(n-1);
	}
}

int main()
{
	print_out_end(10);
}

