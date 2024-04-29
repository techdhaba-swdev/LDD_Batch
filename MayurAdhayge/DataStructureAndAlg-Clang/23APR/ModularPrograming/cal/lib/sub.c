#include "sub.h"
#include <stdarg.h>

int sub(int num1, ...) {
     
    va_list lst;
    va_start(lst, num1);

    int result = va_arg(lst, int); 

    
    for (int i = 1; i < num1; i++) {
        int operand = va_arg(lst, int);
        result =result- operand;
    }

    va_end(lst);
    return result;
}   
/*
int sub(int num1,int num2,int num3)
{
        return (num1-num2-num3);
} 

int sub(int num1,int num2,int num3,int num4)
{
        return (num1-num2-num3-num4);
} */
