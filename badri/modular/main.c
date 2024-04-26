#include "main.h"


int main()
{
	int a = 50;
	int b = 40;
	int c = 30;
	int d = 20;
	printf("add is %d\n",add1(a,b));
	printf("add is %d\n",add2(a,b,c));
	printf("add is %d\n",add3(a,b,c,d));
	printf("sub is %d\n",sub1(a,b));
	printf("sub is %d\n",sub2(a,b,c));
	printf("sub is %d\n",sub3(a,b,c,d));
	printf("mul is %d\n",mul1(a,b));
	printf("mul is %d\n",mul2(a,b,c));
	printf("mul is %d\n",mul3(a,b,c,d));
	printf("div is %d\n",divs1(a,b));
	printf("div is %d\n",divs2(a,b,c));
	printf("div is %d\n",divs3(a,b,c,d));
}
