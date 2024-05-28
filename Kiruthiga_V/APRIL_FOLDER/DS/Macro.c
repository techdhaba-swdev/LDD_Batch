#include <stdio.h>
#define SQUARE(x) ((x) * (x))
int main()
{
int square_of_5 = SQUARE(5);
int square_of_10 = SQUARE(10);
printf("square of 5:%d\n",square_of_5);
printf("square of 10:%d\n",square_of_10);
return 0;
}

