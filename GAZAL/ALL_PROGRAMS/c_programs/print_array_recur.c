#include <stdio.h>

void printArrayElement(int arr[], int size, int index) {
    if (index < size) {
        printf("%d ", arr[index]);
        printArrayElement(arr, size, index + 1);
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    printArrayElement(arr, size, 0);
    
    return 0;
}