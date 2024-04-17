#include <stdio.h>
void reverseArray(int arr[], int size) {
    int i  = 0;
    int j = size - 1;
   
    while (i < j)
    {
       
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
       
        
        i++;
        j--;
    }
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
   
    
    reverseArray(arr, size);
   
    printf("Reversed array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    return 0;
}
