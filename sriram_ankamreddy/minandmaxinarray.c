#include <stdio.h>

int main() {
    int size = 0;
    int largest=0;
    puts("Enter the size of the Array: ");
    scanf("%d", &size);
    int arr [size];
    puts("Enter an array: ");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    printf("The largest array element in the given array is:%d\n", largest);
    int smallest=arr[0];
    for (int i = 0; i < size; i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    printf("The smallest array element in the given array is:%d", smallest);
    return 0;
}
