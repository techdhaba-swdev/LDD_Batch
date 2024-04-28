#include<stdio.h>
#define swap(x,y) {typeof(x) temp=(x) ;(x)=(y) ; (y)=temp;}

int main()
{
	int a = 10;
	int b = 50;
	printf("original value a = %d, b = %d\n ",a,b);
	swap(a,b);
	printf("Swap value a = %d , b =%d\n",a, b);
	return 0;
}
