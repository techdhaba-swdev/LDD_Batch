//sub.c
#include "sub.h"
#include<stdio.h>

//define a static function named print_data
static void print_data()
{
        printf("data finding\n");
}

//Defines a function named sub that takes two integers x and y as parameters. Inside the function, it calculates the result of subtracting x and y using the - operator and returns the result
int sub(int x, int y) {
    return x - y;
}

//Defines a function named subThree that takes three integers x, y and z as parameters. Inside the function, it calculates the result of subtracting x, y and z using the - operator and returns the result

int subThree(int x, int y, int z) {
    return x - y - z;
}

//Defines a function named subFour that takes four integers x, y, z and w as parameters. Inside the function, it calculates the result of subtracting x, y , z and w using the - operator and returns the result
int subFour(int w, int x, int y, int z) {
    return w - x - y - z;
}
