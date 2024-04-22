#include <stdio.h>
#define SWAP(a,b){\
typeof(a) temp = (a); \
(a) = (b);\
(b) = temp;\
}
int main()
{
int x = 5 ,y = 10;
printf("before swapping: x = %d, y= %d\n",x,y);
SWAP (x,y);
printf("after swapping: x = %d, y= %d\n",x,y);
return 0;
}

