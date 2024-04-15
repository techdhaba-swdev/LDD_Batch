#include<stdio.h>

int main() {


    int size = 0;
    puts("Enter the size of the Array: ");
    scanf("%d", &size);
    int arr [size];
    puts("Enter an array: ");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    puts("Reversed Array: ");
    for (int i = size - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    return 0;
}
