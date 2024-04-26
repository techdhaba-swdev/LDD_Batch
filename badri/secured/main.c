#include <stdio.h>
#include "example.h"
int main()
{
	int num1 = 10;
	int num2 = 20;
	
	int sum = add(num1 , num2);

	print_message("the sum is :\n");
	printf("%d\n",sum);

		return 0;
}
