#include "div.h"
#include <stdarg.h>

float div(int num1, ...) {
    float result = (float)num1; 
    va_list lst;
    va_start(lst, num1);

   
    for (int i = 0; i < num1 - 1; i++) {
        int divisor = va_arg(lst, int);
        
        if (divisor != 0) {
            result /= divisor;
        } else {
            
            return 0;
        }
    }

    va_end(lst);
    return result;
}



/*
float div(int num1,int num2)
{
if (num2==0)
{
printf("zero division error");
return 0;
}
        return ((float) num1/num2);
}       

float div(int num1,int num2,int num3)
{
	if (num2==0 || num3==0)
	{
	printf("zero division error");
	return 0;
	}
        return (((float) num1/num2)/num3);
} 

float div(int num1,int num2,int num3,int num4)
{
	if (num2==0 || num4==0 || ((float)num3/num4)<1)
	{
	printf("zero division error");
	return 0;
	}
        return (((float) num1/num2)/((float)num3/num4));
} */
