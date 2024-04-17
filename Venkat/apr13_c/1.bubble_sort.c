#include<stdio.h>
int main()
{
    int arr[5]={4,2,5,1,8};
     int temp;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<4;j++){
            if(arr[i]>arr[j]){
                temp =arr[j];
                arr[j]=arr[i];
                arr[i] =temp;


            }
        

        }
        
    }for(int i=0;i<5;i++){
    printf("%d\t",arr[i]);
    }
}