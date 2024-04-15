<<<<<<< HEAD:BHAVANA/15thapril/macroswap.c
#include <stdio.h>

#define SWAP(a, b) { \
    typeof(a) temp = (a); \
    (a) = (b); \
    (b) = temp; \
}

int main() {
    int x = 5, y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    SWAP(x, y);
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
=======
#include<stdio.h>
#define SWAP(a,b) do { \
	(a)= (a) + (b);\
	(b) = (a) - (b);\
	(a) = (a) - (b);\
} while(0)

int main()
{
	int x = 5, y = 6;
	printf("Before swapping: x = %d, y = %d\n", x, y);
	SWAP(x, y);
	printf("After swapping: x = %d, y = %d\n", x, y);
	return 0;
>>>>>>> b261421 (Added day09 training codes):Ganavi_M/Searching/macroswap.c
}
