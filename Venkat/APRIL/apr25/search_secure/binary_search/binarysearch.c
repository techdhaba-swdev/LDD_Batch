#include "binarysearch.h"
int binarysearch(int arr[],int target){
    int start =0;
    //int end =sizeof(arr)/sizeof(arr[0])-1;
    int end = 8;
    while(start<=end){
        // int mid = (start+end)/2 //if the int number is large may exists integer it may surppass int value it prevents int out of bound
        int mid = start + (end-start)/2;
	if(target == arr[mid]) {
		return mid;
                  }
        else if(target <arr[mid]){
                end = mid-1 ;
        }
        else {
            start = mid+1;
        }
        return -1; // target is not found
    
    }

}
