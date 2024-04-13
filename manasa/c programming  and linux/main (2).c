#include <stdio.h>
void printArray(int arr[], int size, int index) {
    if (index == size)
        return;
    printf("%d ", arr[index]);
    printArray(arr, size, index + 1);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array elements: ");
    printArray(arr, size, 0);
    
    return 0;
}