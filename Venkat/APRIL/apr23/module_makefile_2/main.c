#include "main.h"

int main()
{
	printf("sum is %d\n",add2(10,15));
	printf("sum is %d\n",add3(10,15,20));
	printf("sum is %d\n",add4(10,15,20,25));
	printf("sub is %d\n",sub2(20,10));
	printf("sub is %d\n",sub3(30,15,10));
	printf("sub is %d\n",sub4(50,10,5,20));
	printf("mul is %d\n",mul2(10,15));
	printf("mul is %d\n",mul3(5,10,15));
	printf("mul is %d\n",mul4(5,10,15,20));
	printf("div is %f\n",div2(5,10));
	printf("div is %f\n",div3(5,10,15));
	printf("div is %f\n",div4(5,10,15,20));
	return 0;
}
