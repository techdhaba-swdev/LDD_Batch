#include <stdio.h>


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int size, target;
   
    printf("Enter the size of the array: ");
    scanf("%d", &size);
   
    int arr[size];
   
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
   
    printf("Enter the element to search: ");
    scanf("%d", &target);
   
    
    int index = linearSearch(arr, size, target);
   
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }
   
    return 0;
}
