#include <stdarg.h>
#include"add.h"

int add(int num1, ...) {
    int sum = 0;
    va_list lst;
    va_start(lst, num1);

    for (int i = 0; i < num1; i++) {
        sum =sum + va_arg(lst, int);
    }

    va_end(lst);
    return sum;
}
/*
int add(int num1,int num2,int num3)
{
        return (num1+num2+num3);
} 

int add(int num1,int num2,int num3,int num4)
{
        return (num1+num2+num3+num4);
} */
