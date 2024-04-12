#include <stdio.h>
#include <stdlib.h>

int* allocateIntArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); 
    }
    return arr;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = allocateIntArray(size);

    printf("Memory allocation successful.\n");
   
    free(arr);

    return 0;
}
