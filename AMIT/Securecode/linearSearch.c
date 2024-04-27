#include<stdio.h>
#include"linear.h"

int main() {
    int arr[10] = {3, 4, 1, 7, 5, 8, 11, 42, 3, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int index = linearSearch(arr, size, key);

    if (index == -1) {
        printf("The element is not present in the array.\n");
    } else {
        printf("The element is present at arr[%d].\n", index);
    }

    return 0;
}
