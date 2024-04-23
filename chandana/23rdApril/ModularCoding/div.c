#include <stdio.h>

int div(int x,int y){
	if(y!=0){
		return x/y;
	}
	else
	{
		printf("error division");
		return 0;
	}
}

