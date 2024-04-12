#include <stdio.h>
 int main()
 {
    int arr[6]= {1,2,3,4,5};
    for(int i=5;i>0;i--){
        arr[i] = arr[i-1];

    }
    printf("enter the value to first position\n");
    scanf("%d",&arr[0]);
    printf("updated array:\t");
    for(int i=0;i<6;i++){
        printf("%d\t",arr[i]);
        
    }
    printf("\n");
    return 0;
 }