#include <stdio.h>
#include "factorial.h"

int main()
{
	int num = 5;
	int result = calculateFactorial(num);
	printf("factorial of %d is: %d\n",num,result);
	return 0;
}
