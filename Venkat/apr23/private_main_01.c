#include <stdio.h>
#include "private_01.h"

int main() {

	int result;

	result = private_static_function(5 ,10);
	printf("the result add %d\n",result);
	
	return 0;
}
