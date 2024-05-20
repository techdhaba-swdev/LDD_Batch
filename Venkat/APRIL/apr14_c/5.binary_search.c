#include <stdio.h>
int binarysearch(int arr[],int target){
    int start =0;
    //int end =sizeof(arr)/sizeof(arr[0])-1;
    int end =8;
    while(start<end){
        // int mid = (start+end)/2 //if the int number is large may exists integer it may surppass int value
        int mid = start + (end-start)/2;
        if(target < mid){
        end = mid-1 ;
        }
        else if(target>mid){
            start = mid+1;
        }
        else {
            return mid;
        }
    
    }

}
int main(){
    int arr[9]={11,24,37,45,55,61,73,86,98};
    int target = 86;
    int ans = binarysearch(arr,target);
    printf("the target at index %d\n",ans);
    }