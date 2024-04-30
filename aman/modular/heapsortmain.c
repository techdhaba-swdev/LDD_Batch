#include <stdio.h>//This line includes the standard input-output library, which provides functions like printf and scanf
#include "heapsort.h"//This line includes the header file heap_sort.h, which contains the function declaration for heapsort

#define SIZE 10//This line defines a macro SIZE with the value 10. This macro is used to specify the size of the array to be sorted.

int main() {//This line marks the beginning of the main function, which is the entry point of the program.
    int arr[SIZE] = {12, 11, 13, 5, 6, 7, 2, 14, 3, 9};//This line declares an integer array arr of size SIZE and initializes it with some values. These values represent the elements to be sorted.

    printf("Original array:\n");// This line prints a message indicating that the array before sorting is being displayed.
    for (int i = 0; i < SIZE; i++)//This line starts a for loop that iterates through each element of the array.
        printf("%d ", arr[i]);//Inside the loop, this line prints each element of the array.
    printf("\n");//After printing all elements, this line prints a newline character to move to the next line.

    heap_sort(arr, SIZE);// This line calls the heap_sort function to sort the array arr of size SIZE using the heap sort algorithm.

    printf("Sorted array:\n");//This line prints a message indicating that the array after sorting is being displayed.
    for (int i = 0; i < SIZE; i++)//This line starts a for loop that iterates through each element of the array.
        printf("%d ", arr[i]);//Inside the loop, this line prints each element of the array.
    printf("\n");//After printing all elements, this line prints a newline character to move to the next line.


    return 0;//This line signifies the successful completion of the main function and returns a status code of 0, indicating that the program executed successfully.
}

