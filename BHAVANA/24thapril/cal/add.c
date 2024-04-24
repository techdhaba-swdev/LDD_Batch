#include "add.h"
#include<stdio.h>
static void print_data()
{
	printf("data found\n");
}
int add(int x, int y) {
    return x + y;
}

int addThree(int x, int y, int z) {
    return x + y + z;
}

int addFour(int w, int x, int y, int z) {
    return w + x + y + z;
}
