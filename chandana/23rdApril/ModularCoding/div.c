#include <stdio.h>
#include "div.h"

static void print_data(){
	printf("In division\n");
}

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

