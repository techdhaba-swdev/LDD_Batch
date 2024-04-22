#include <stdio.h>

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 23;

    int index = searchElement(arr, size, element);

    if (index != -1) {
        printf("Element %d found at index %d\n", element, index);
    } else {
        printf("Element %d not found in the array\n", element);
    }

    return 0;
}
