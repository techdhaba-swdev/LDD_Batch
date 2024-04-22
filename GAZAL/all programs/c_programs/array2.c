#include <stdio.h>
int linearSearch(int arr[], int size, int element) {
    
    for (int i = 0; i < size; i++) {
        
        if (arr[i] == element)
            return i;
    }
   
    return -1;
}

int main() {
    int size;
    printf("enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int element;
    printf("enter the element to search: ");
    scanf("%d", &element);
    int index = linearSearch(arr, size, element);

    if (index != -1)
        printf("element %d found at %d\n", element, index);
    else
        printf("element %d not found \n", element);

    return 0;
}