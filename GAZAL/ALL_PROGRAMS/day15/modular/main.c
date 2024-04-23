#include "main.h"
int main(){
	//add
	printf("add is %d",add(4,5));
	printf("add is %d",add2(4,5,6));
	printf("add is %d",add3(4,5,6,7));
	//subtract
	printf("sub is %d",sub(14,5));
	printf("sub is %d",sub4(14,5,4,3));
	printf("sub is %d",sub3(14,5,3));
	//multiply
    printf("multiplyis %d",mul(2,3));
	printf("multiply is %d",mul3(2,3,2));
	printf("multiply is %d",mul4(2,3,3,2));
	//divide
	printf("divide is %f",div2(15,3));
	printf("divide is %f",div3(2,3,2));
	printf("divide is %f",div4(2,3,3,2));

	return 0;
} 
