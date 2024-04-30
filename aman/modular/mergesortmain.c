#include <stdio.h>//This line includes the standard input/output library which provides functions like printf and scanf for input/output operations.
#include "mergesort.h"//This line includes a header file named mergesort.h
#define SIZE 10 //This line defines a symbolic constant named SIZE with a value of 10. This constant is used to specify the size of the array

int main() {//This line starts the definition of the main function, which is the entry point of the program. The main function returns an integer value.
    int arr[SIZE] = {12, 11, 13, 5, 6, 7, 2, 14, 3, 9};//This line declares an array named arr of integers with a size of SIZE (which is 10 in this case) and initializes it with the given values.

    printf("Original array:\n");//This line uses the printf function to print the string "Original array:\n" to the standard output 
    for (int i = 0; i < SIZE; i++)//This is a loop that iterates over the array arr. SIZE is the size of the array. It starts from index 0 and goes up to SIZE - 1
        printf("%d ", arr[i]);//In each iteration, it prints the value of the element at index i of the array using printf with the format specifier %d, which indicates an integer.
    printf("\n");//After printing all elements of the array, it prints a newline character \n to move to the next line.

    merge_sort(arr, 0, SIZE - 1);//    This line calls a function named merge_sort and passes three arguments to it. The first argument is the array arr, which is to be sorted. The second argument is the starting index of the array to be sorted, which is 0, indicating the beginning of the array. The third argument is the ending index of the array to be sorted, which is SIZE - 1, indicating the last element of the array.

    printf("Sorted array:\n");//    This line simply prints "Sorted array:" followed by a newline character \n.
    for (int i = 0; i < SIZE; i++)//This is another loop similar to the first one, but it prints the contents of the array arr after it has been sorted by the merge_sort function.
        printf("%d ", arr[i]);//It iterates over the array arr from index 0 to SIZE - 1, printing each element using printf with the format specifier %d.
    printf("\n");//After printing all elements of the sorted array, it prints a newline character \n to move to the next line.

    return 0;//    This line signifies the end of the main function and returns 0, indicating successful execution of the program.
}

