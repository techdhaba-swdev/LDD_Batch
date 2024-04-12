#include<stdio.h>
struct list{
int data[4];
int length;
};
int main(){

struct list arr;
int temp,num;

for(int i=0; i<3;i++)
{
printf("enter the number%d :- ",i+1);
scanf("%d", &arr.data[i]);
//printf("%d ",arr.data[i]);
}
arr.length=3;

printf("\ngive the number to insert number at inde 1 :- ");
scanf("%d",&num);

for(int j=0; j< (arr.length)+1 ;j++ )
{
if(j==1){
temp=arr.data[j];
arr.data[j]=num;
}

else if (j > 1){
temp = arr.data[j] +temp;
arr.data[j] = temp- arr.data[j];
temp= temp - arr.data[j];
}
}
arr.length=4;
printf("\nAfter inserting value in array:- \n");
for(int k=0; k<arr.length;k++)
{
printf("%d ",arr.data[k]);
} 



}


