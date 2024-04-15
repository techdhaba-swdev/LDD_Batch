#include <stdio.h>

int main() {
    int size = 0;
    puts("Enter the size of the Array: ");
    scanf("%d", &size);
    int arr[size];
    puts("Enter an array: ");
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
   
    int element = 0;
    puts("Enter the Element to search in the Array: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++){
        if(arr[i]==element){
            printf("The searching element %d is present in the given array",element);
        }
    }
   
   

    return 0;
}


