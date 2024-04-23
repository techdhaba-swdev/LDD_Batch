#include<stdio.h>
void printarray(int arr[], int size, int index){ //it will define array,size,index
    if(index==size){// it checks index is eual to size or not if it is function returns , it will for  recursion  
        return;
    }
    printf("%d",arr[index]);//print the elements in the current index 
    printarray(arr,size,index+1); //it calls recursively itself with next index (index +1)
}
int main(){
    int arr[]={ 1, 3, 5, 7, 9};
    int size = sizeof(arr)/sizeof(arr[0]);//calculates the number of array elements 
    printf("array of elements:");
    printarray(arr,size,0);
    printf("\n");
    return 0;
}