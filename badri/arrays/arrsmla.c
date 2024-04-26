#include <stdio.h>
void findLargestAndSmallest(int arr[], int size) {
    int smallest = arr[0];
    int largest = arr[0];
   
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
   
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);
}

int main() {
    int size;
   
    printf("Enter the size of the array: ");
    scanf("%d", &size);
   
    int arr[size];
   
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
   
    // Find the largest and smallest elements
    findLargestAndSmallest(arr, size);
   
    return 0;
}
