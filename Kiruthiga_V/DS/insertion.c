#include <stdio.h>

int main() {
    int arr[5]; // Array of size 5
    int i, num;

    // Input 3 elements
    printf("Enter 3 elements:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    // Input new number to insert
    printf("Enter the number to insert: ");
    scanf("%d", &num);

    // Shift elements to make space for the new number at index 1
    for (i = 2; i >= 1; i--) {
        arr[i+1] = arr[i];
    }

    // Insert new number at index 1
    arr[1] = num;

    // Print the array
    printf("Array after inserting the new number:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




