#include "div.h"
#include<stdio.h>
static void print_data()
{
        printf("found\n");
}

int my_div(int x, int y) {
    if (y == 0 )
    {
	    printf("error: division by zero\n");
	    return 0;
    }
    return x / y;
}
