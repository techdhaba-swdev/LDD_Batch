#include<stdio.h>
void array(int arr[],int start,int length){
    if(start==length){ // if index and lenght of array are equal it runs
        return;
    }
    printf("%d\t",arr[start]);
   array(arr,start+1,length);
}
int main()
{
 int arr[]= {1,2,3,4,5,6};
 int length = sizeof(arr)/sizeof(0);
  // need to add next index upto it reaches the length of array and then it returns each elements in stacks
 //recursiv call
 printf("accessing elements using recursion\n");
 array(arr,0,length);

 
 
}
