//main.c
#include "main.h"

//Defines a static function named print_data.
static void print_data()

{
	printf("printing main\n");
}


int main(){
	print_data(); // call the print_data function to print a message.

    //print the result of addition functions
    printf(" add of 2 no: %d\n", add(4, 5));
    printf(" add of 3 no: %d\n", addThree(4, 5, 6));
    printf(" add of 4 no: %d\n", addFour(4, 5, 6, 7));
    
    //print the result of subtraction functions
    printf(" sub of 2 no: %d\n", sub(14, 5));
    printf(" sub of 3 no: %d\n", subThree(14, 5, 4));
    printf(" sub of 4 no: %d\n", subFour(14, 5, 9, 7));

    //print the result of division function
    printf(" div of 2 no: %d\n",my_div(20, 4));i

    //print the result of multiplication functions
    printf(" mul of 2 no: %d\n", mul(4, 5));
    printf(" mul of 3 no: %d\n", mulThree(4, 5, 8));
    printf(" mul of 4 no: %d\n", mulFour(4, 5, 9, 8));


    return 0;
}
