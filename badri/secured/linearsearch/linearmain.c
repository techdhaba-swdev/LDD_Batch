#include <stdio.h>  // Including standard input/output header file.
#include "linearsearch.h" //Including the header file for linear search.

int main() {
    int arr[] = {5, 10, 15, 20, 25};  //Initializing an array.
    int n = sizeof(arr) / sizeof(arr[0]); //Calculating the size of the array
    int target = 15; //Defining the target element to search.
    int result = linearSearch(arr, n, target); //Calling the linear search function.
    if (result != -1) //Checking if the element is found.
        printf("Element found at index: %d\n", result);//Printing the index of the found element.
    else //Executing if the element is not found.
        printf("Element not found\n");//Printing that the element is not found.
 	return 0; // indicate successful termination.
    
}
