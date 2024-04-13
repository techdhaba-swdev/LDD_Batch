#include <stdio.h>
#include <stdlib.h> 
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int* allocateIntArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int)); 

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return arr;
}

int main() {
    int num1 = 10, num2 = 20;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = allocateIntArray(size);
    printf("Memory allocation successful. Array of size %d created.\n", size);
    free(arr);
    printf("Memory freed.\n");

    return 0;
}