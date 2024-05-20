#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("1st element: %d\n", *ptr);

    ptr++;
    printf("2nd element: %d\n", *ptr);

    ptr++;
    printf("3rd element: %d\n", *ptr);

    ptr++;
    printf("4th element: %d\n", *ptr);

    ptr++;
    printf("5th element: %d\n", *ptr);

    return 0;
}
