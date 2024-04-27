#include <stdio.h>//This line includes the standard input-output library, which provides functions like printf() and scanf() for input and output operations.
#include "linearsearch.h"//This line includes the header file linear_search.h, which contains the declaration of the linearSearch function. This inclusion allows the main function to use the linearSearch function

int main() {//This line defines the main function, which serves as the entry point of the program. It returns an integer value to the operating system upon completion.
    int arr[] = {2, 4, 6, 8, 10};//This line declares an integer array arr and initializes it with values {2, 4, 6, 8, 10}. This array will be used for demonstration purposes to perform a linear search operation.
    int n = sizeof(arr) / sizeof(arr[0]);//This line calculates the number of elements in the array arr by dividing the total size of the array (sizeof(arr)) by the size of its first element (sizeof(arr[0])). This calculation results in the total number of elements in the array, which is stored in the variable n.
    int target = 6;// This line declares an integer variable target and initializes it with the value 6. This value represents the target element that we want to search for in the array.

    int index = linearSearch(arr, n, target);//This line calls the linearSearch function with three arguments: the array arr, its size n, and the target element target. The return value of the function, which represents the index of the target element in the array (or -1 if not found), is stored in the variable index.

    if (index != -1) {//This line starts an if statement to check if the returned index value from the linearSearch function is not equal to -1. This condition ensures that the target element was found in the array.
        printf("Element %d found at index %d\n", target, index);//This line prints a message to the console indicating that the target element target was found at index index in the array.
    } else {//This line starts an else block, which means the target element was not found in the array (i.e., the returned index value is -1).
        printf("Element %d not found\n", target);//This line prints a message to the console indicating that the target element target was not found in the array.
    }

    return 0;
}

