#include "linearsearch.h"//This line includes the header file linear_search.h, which contains the declaration of the linearSearch function. This inclusion allows the implementation of the function in this file to know the function's signature and types of parameters.

int linearSearch(int arr[], int n, int target) {//This line defines the linearSearch function. It specifies that the function takes three parameters: an integer array arr[], its size n, and the target integer value to search for target. The function returns an integer value representing the index of the target element if found, or -1 if the target element is not found in the array.

    	for (int i = 0; i < n; i++) {//This line starts a for loop that iterates over each element of the array arr[] from index 0 to n-1. It initializes the loop counter i to 0 and increments it by 1 in each iteration until it reaches n
    
	    	if (arr[i] == target) {//This line checks if the current element of the array (arr[i]) is equal to the target value (target). If they are equal, it means the target element is found in the array.
            
			return i; //This line returns the index i, indicating the position of the target element in the array.
        }
    }
    return -1; //These lines close the if block and the linearSearch function definition, respectively. If the loop completes without finding the target element, it means the target is not present in the array, so -1 is returned to indicate that the target element is not found.
}

