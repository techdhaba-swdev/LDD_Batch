#include<stdio.h>
int main()
{
	int x =5, y =10;
	x = x + y; // now x became 15
	y = x- y ;  //now y become 5
        x = x-y;   //now x become 10
        printf("x = %d , y = %d ",x ,y);
	return 0;
}	

