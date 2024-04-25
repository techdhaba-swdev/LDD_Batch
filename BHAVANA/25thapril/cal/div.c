//div.c
#include "div.h"
#include<stdio.h>

//define a static function named print_data
static void print_data()
{
        printf("found\n");
}

//Defines a function named divide that takes two integers x and y as parameters. Inside the function, it checks if y is not equal to zero to avoid division by zero error. If y is not zero, it calculates the result of dividing x by y using the / operator and returns the quotient. Otherwise, it returns 0

int my_div(int x, int y) {
    if (y == 0 )
    {
	    printf("error: division by zero\n");
	    return 0;
    }
    return x / y;
}
