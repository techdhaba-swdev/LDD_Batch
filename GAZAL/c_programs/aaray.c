#include <stdio.h>

int main() {
    int arr[5]; 
    int i, new;

    printf("Enter 3 elements:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the new insert at index 1: ");
    scanf("%d", &new);

    for (i = 2; i >= 1; i--) {
        arr[i+1] = arr[i];
    }

    arr[1] = new;

    printf("Array after insertion:\n");
    for (i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}