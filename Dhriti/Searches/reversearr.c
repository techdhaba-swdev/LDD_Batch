#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(int arr[], int size){
    int start = 0;
    int end = size - 1;

    while  (start < end){
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}
void printArray(int arr[], int size){
    for (int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int size= sizeof(arr) / sizeof(arr[0]);
    printf("original array: ");
    printArray(arr, size);
    reverseArray(arr, size);
    printf("reversed array: ");
    printArray(arr, size);

    return 0;
}
