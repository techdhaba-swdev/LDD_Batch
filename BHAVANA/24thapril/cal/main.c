#include "main.h"
static void print_data()

{
	printf("printing main\n");
}
int main(){
	print_data();
    printf(" add of 2 no: %d\n", add(4, 5));
    printf(" add of 3 no: %d\n", addThree(4, 5, 6));
    printf(" add of 4 no: %d\n", addFour(4, 5, 6, 7));

    printf(" sub of 2 no: %d\n", sub(14, 5));
    printf(" sub of 3 no: %d\n", subThree(14, 5, 4));
    printf(" sub of 4 no: %d\n", subFour(14, 5, 9, 7));


    printf(" div of 2 no: %d\n",my_div(20, 4));
    //printf(" div of 3 no: %d\n", divThree(20, 4, 9));
    //printf(" div of 4 no: %d\n", divFour(20, 4, 8, 9));


    printf(" mul of 2 no: %d\n", mul(4, 5));
    printf(" mul of 3 no: %d\n", mulThree(4, 5, 8));
    printf(" mul of 4 no: %d\n", mulFour(4, 5, 9, 8));


    return 0;
}
