#include "div.h"
#include<stdio.h>
int my_div(int x, int y) {
    if (y == 0 )
    {
	    printf("error: division by zero\n");
	    return 0;
    }
    return x / y;
}
