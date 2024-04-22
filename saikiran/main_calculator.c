#include<stdio.h>
#include "calculator.h"
int main()
{
        int a = 10;
        int b= 5;
        printf("add %d+%d = %d/n", a,b,add(a,b));
        printf("sub %d-%d = %d/n", a,b,subtraction(a,b));
        printf("mul %d*%d = %d\n",a,b,multiplication(a,b));
        printf("div %d/%d = %f\n",a,b,division(a,b));
        return 0;
}


