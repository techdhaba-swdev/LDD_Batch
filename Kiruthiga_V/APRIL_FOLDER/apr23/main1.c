#include"main.h"
int main()
{
	printf("sum is %d\n",add2(10,20));
	printf("sum is %d\n",add3(10,20,30));
	printf("sum is %d\n",add4(10,20,30,50));
	printf("sub is %d\n",sub2(20,10));
	printf("sub is %d\n",sub3(20,10,5));
	printf("sub is %d\n",sub4(90,10,10,5));
	printf("mul is %d\n",mul2(20,10));
	printf("mul is %d\n",mul3(20,10,200));
	printf("mul is %d\n",mul4(20,10,3,50));
	printf("div is %f\n",div2(20,10));
	printf("div is %f\n",div3(200,100,2));
	printf("div is %f\n",div4(500,5,2,5));
	return 0;

}
