#include <stdio.h>
int main()
{
    int arr[6]={1,2,3,4,5};
    
    for(int i=5;i>0;i--){
        arr[i] =arr[i-1];
        }
    printf("enter the value to index 1\n");
    scanf("%d",&arr[0]);
    for(int i=0;i<6;i++){
        printf("%d\t",arr[i]);
    }
    return 0;


}