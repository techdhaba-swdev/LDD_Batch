#include<stdio.h>

#define SWAP(a,b) \
	int temp =  (a);\
	(a) = (b) ;\
	(b) = temp;\
//}while(0)

int main()
{
	int x=5;
	int y=10;

	printf("x=%d ,y=%d",x,y);
           SWAP(x,y);
	printf("after swaping x=%d , y=%d",x,y);
}
