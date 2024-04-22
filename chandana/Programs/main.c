#include <stdio.h>
#include "add.h"

int add(int x,int y);
int sub(int x,int y);
int mul(int x,int y);
int div(int x,int y);

int main() {
	printf("add is : %d\n",add(4,5));
	printf("sub is : %d\n",sub(3,2));
        printf("mul is : %d\n",mul(2,5));	
	printf("div is : %d\n",div(10,2));
	return 0;
}

