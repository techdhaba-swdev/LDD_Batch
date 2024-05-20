#include<stdio.h>
#include "calculator.h"
int main()
{
int a =10,b =5;
printf("addition%d\n",add(a,b));
printf("subtraction%d\n",subtract(a,b));
printf("multiplication%d\n",multiply(a,b));
printf("division%0.2f\n",divide(a,b));
return 0;
}
