#include <stdio.h>

int main() {
    int arr[5]; // Array of size 5
    int i;

    // Input 3 elements
    printf("Enter 3 elements:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    // Deleting number at index 0 by shifting elements
    for (i = 0; i < 2; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the array
    printf("Array after deleting the number at index 0:\n");
    for (i = 0; i < 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

