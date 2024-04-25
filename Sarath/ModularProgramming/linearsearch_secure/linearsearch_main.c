#include<stdio.h>
#include"linear.h"
int main()
{
	 int arr[5];
  	 int find;
   	 printf("Enter numbers:");
  	 for(int i=0;i<5;i++)
   	 {
       		 scanf("%d",&arr[i]);
         }
   	 printf("Enter element to find:");
   	 scanf("%d",&find);
   	 int result=linearsearch(arr,find);
   	 if (result == -1)
   	 {
        	printf("Element not found\n");
   	 }
   	 else
   	 {
        	printf("Element found at index %d\n", result);
   	 }

   	 return 0;
}
