//add.c
#include "add.h"
#include<stdio.h>

//define a static function named print_data
static void print_data()
{
	printf("data found\n");
}


//Defines a function named add that takes two integers x and y as parameters. Inside the function, it calculates the sum of x and y using the + operator and returns the result
int add(int x, int y) {
    return x + y;
}
//Defines a function named addThree that takes three integers x , y and z as parameters. Inside the function, it calculates the sum of x,  y and z  using the + operator and returns the result
int addThree(int x, int y, int z) {
    return x + y + z;
}
//Defines a function named addFour that takes four integers x, y , z and w as parameters. Inside the function, it calculates the sum of x, y , w and z using the + operator and returns the result
int addFour(int w, int x, int y, int z) {
    return w + x + y + z;
}
