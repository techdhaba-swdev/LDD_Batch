#include <stdio.h>
#include "su.h"
int swap(int x , int y )
{
        int z = 0 ;
        z = x;
	x = y;
	y = z;
	return (x,y);
}

