#include <stdio.h>
#define swap(t,a,b) (t=a , a=b ,b=t)
int main()
{
	int temp = 0;
	int num1 = 10;
	int num2 = 11;
	swap(temp,num1,num2);
	printf("swap of number %d\t%d\n",num1,num2);
}
