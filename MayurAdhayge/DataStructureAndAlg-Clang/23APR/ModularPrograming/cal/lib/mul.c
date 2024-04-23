#include"mul.h"
#include<stdarg.h>



int mul(int num1, ...) {
    int mul = 1;
    va_list lst;
    va_start(lst, num1);

    for (int i = 0; i < num1; i++) {
        mul=mul*va_arg(lst, int);
    }

    va_end(lst);
    return mul;
}

      
/*
int mul(int num1,int num2,int num3)
{
        return (num1*num2*num3);
} 

int mul(int num1,int num2,int num3,int num4)
{
        return (num1*num2*num3*num4);
} */
