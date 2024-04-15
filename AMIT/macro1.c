#include<stdio.h>

#define SQUARE(x) ( (x) * (x) )

int main()
{
	int n=5;
	int y=10;
	printf("square of %d is=%d ",n,SQUARE(n));
	printf("square of %d is=%d ",y,SQUARE(y));
       return 0;
}

