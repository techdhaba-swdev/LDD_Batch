/*how insertion sort works
1.it will sort till index method from current position to left most poistion index
2.example if index if index is 0 it will sort 0 and till 1 index 
3.if sorted after it start from index will be 1 it will sort till index 2 and go on
will sort from current index to left most index thats how it works*/
#include<stdio.h>
int main(){
    int arr[6]={4,3,6,1,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                }
                else {
                    break; // if j loop going for next it will already sorted to indext no need to sort and check elements its already sorted
                }
            }
        }
        for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
        }
    }