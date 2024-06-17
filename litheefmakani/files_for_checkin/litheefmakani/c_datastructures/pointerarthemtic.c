#include <stdio.h>
void accessArrayElements(int *arr, int size) {
    printf("Accessing array elements using pointer arithmetic:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i+1, *(arr + i)); 
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    accessArrayElements(arr, size);

    return 0;
}