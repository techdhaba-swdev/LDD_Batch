#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int)); // Insecure memory allocation

    // Use the array...
    
    free(arr);
    return 0;
}
