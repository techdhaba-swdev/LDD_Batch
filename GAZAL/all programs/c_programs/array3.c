#include <stdio.h>

int main() {
    int arr[] = {25, 5, 8, 20, 2, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest)
            largest = arr[i];
        else if (arr[i] < smallest)
            smallest = arr[i];
    }

  
    printf("large element: %d\n", largest);
    printf("smaall element: %d\n", smallest);

    return 0;
}