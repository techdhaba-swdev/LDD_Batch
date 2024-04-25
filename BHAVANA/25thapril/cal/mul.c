//mul.c
#include "mul.h"
#include<stdio.h>

//define a static function named print_data
static void print_data()
{
        printf("data\n");
}

//Defines a function named mul that takes two integers x and y as parameters. Inside the function, it calculates the product of x and y using the * operator and returns the result.
int mul(int x, int y) {
    return x * y;
}

//Defines a function named mulThree that takes three integers x, y, and z as parameters. Inside the function, it calculates the product of x, y and z using the * operator and returns the result.
int mulThree(int x, int y, int z) {
    return x * y * z;
}

//Defines a function named mulFour that takes four integers x, y, z and was parameters. Inside the function, it calculates the product of x, y, z and w using the * operator and returns the result.
int mulFour(int w, int x, int y, int z) {
    return w * x * y * z;
}

