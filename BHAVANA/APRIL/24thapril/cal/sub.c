#include "sub.h"
#include<stdio.h>
static void print_data()
{
        printf("data finding\n");
}



int sub(int x, int y) {
    return x - y;
}

int subThree(int x, int y, int z) {
    return x - y - z;
}

int subFour(int w, int x, int y, int z) {
    return w - x - y - z;
}
