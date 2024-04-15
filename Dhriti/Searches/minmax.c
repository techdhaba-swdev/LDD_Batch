#include <stdio.h>
void findMinMax(int arr[], int size, int *min, int *max){
    *min = *max = arr[0];
    for(int i=1;i<size;i++){
        if (arr[i] < *min){
            *min = arr[i];
        }
        else if (arr[i] > *max){
            *max = arr[i];
        }
    }
}
int main() {
    int arr[] = {4,6,9,10,15,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, size, &min, &max);
    printf("the smallest element in the array is:  %d\n", min);
  
    printf("the largest element in the   array is: %d\n", max);

    return 0;
}
