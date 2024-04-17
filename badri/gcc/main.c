#include <stdio.h>
#include"add.c"
#include"sub.c"
#include"mul.c"
#include"div.c"

int main()
{
	int x = 6;
	int y =3;
	printf("addition of x&y is %d\n",add(x,y));
	printf("substraction of x&y %d\n",sub(x,y));
	printf("multiplication of x&y %d\n",mul(x,y));
	printf("division of x&y %d\n",div(x,y));

}
