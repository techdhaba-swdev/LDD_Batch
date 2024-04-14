#include<stdio.h>
void swap( int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{

	int x = 10;
	int y = 15;
	printf("Before swaping: x = %d, y=%d\n",x ,y);
	swap(&x,&y);
	printf("After swaping: X =%d, y = %d\n",x,y);
	return 0;
}
