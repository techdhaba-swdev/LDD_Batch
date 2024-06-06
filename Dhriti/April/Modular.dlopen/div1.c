#include "div1.h"

int div_2(int x, int y)
{
	if(y==0) {
		return("Error");
	}

	return x/y;
}

int div_3(int x, int y, int z)
{
        if(y==0||z==0) {
                return("Error");
        }

        return x/y/z;
}

