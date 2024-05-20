#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; 

    printf("Element at position 0: %d\n", *ptr);
    printf("Element at position 2: %d\n", *(ptr + 2));
    printf("Element at position 4: %d\n", *(ptr + 4));

    return 0;
}

