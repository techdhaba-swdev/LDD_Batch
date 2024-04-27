#include "linearsearc.h"
#include<stdio.h>
#include<stddef.h>//for null
		  //
// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
	//input validation 
	if(arr ==  NULL || size <=0) {
		return -1;//invalid inpput
			}
    for (int i = 0; i < size; i++) {
	    //bonds checking
	    if(i >= size){
		    return -1;//out of bounds
	    }
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}
