#include <stdio.h>
#include "main.h"

int main() {
	printf("add is %d\n",add(4,5));
	printf("add_three no. %d\n",add_three(3,5,6));
	printf("add four no. %d\n",add_four(1,2,3,4));
	printf("sub is %d\n",sub(14,5));
	printf("sub_three %d\n",sub_three(9,3,3));
	printf("mul is %d\n",mul(2,3));
	printf("mul_three %d\n",mul_three(1,2,3));
	printf("div is %d\n",div(10,2));

	return 0;
}
