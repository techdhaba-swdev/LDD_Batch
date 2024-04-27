#include <stdio.h>//This line includes the standard input-output header file stdio.h, which provides functions like printf() and scanf() for input and output operations.
#include "bubble_sort.h"//This line includes the header file "bubble_sort.h" in the source file. It allows us to use the function bubbleSort declared in bubble_sort.h and defined in bubble_sort.c.

int main() {//This line defines the main function, which is the entry point of the program. Execution of the program begins from here.
    int arr[] = {64, 34, 25, 12, 22, 11, 90};// This line declares and initializes an integer array arr with some initial values. This array will be sorted using the Bubble Sort algorithm.
    int size = sizeof(arr) / sizeof(arr[0]);//This line calculates the size of the array arr by dividing the total size of the array (sizeof(arr)) by the size of its first element (sizeof(arr[0])). This expression evaluates to the number of elements in the array.

    printf("Array before sorting: ");//This line prints a message indicating that the array is about to be sorted onto the standard output (typically the console).
    for (int i = 0; i < size; i++) {//This is a for loop that iterates over each element of the array arr. Inside the loop, each element of the array is printed using printf().
        printf("%d ", arr[i]);
    }
    printf("\n"); //This line prints a newline character, causing the output to move to the next line.

    bubbleSort(arr, size);//This line calls the bubbleSort function, passing the array arr and its size size as arguments. The function sorts the array using the Bubble Sort algorithm.

    printf("Array after sorting: ");//This line prints a message indicating that the array has been sorted onto the standard output.
    for (int i = 0; i < size; i++) {//This is another for loop that iterates over each element of the array arr. Inside the loop, each element of the sorted array is printed using printf().
        printf("%d ", arr[i]);
    }
    printf("\n"); //This line prints a newline character, causing the output to move to the next line.

    return 0;//This line signifies the successful termination of the main function and the program as a whole. It returns an exit status of 0 to the operating system, indicating that the program executed successfully.
}


//secure code - This implementation is secure because it performs bounds checking and doesn't allow buffer overflows or other memory-related issues.

