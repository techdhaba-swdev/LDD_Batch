#include <stdio.h>

<<<<<<< HEAD:BHAVANA/15thapril/reversearray.c
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);


  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
=======
void reverseArray(int arr[], int size) {
    int start = 0;      
    int end = size - 1; 
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printArray(arr, size);

    return 0;
>>>>>>> b261421 (Added day09 training codes):Ganavi_M/Searching/reversearray.c
}
