#include<stdio.h>
void printArray(int arr[],int size,int index){
	if(index>=size)
		return;
	printf("%d\n",arr[index]);
	printArray(arr,size,index+1);
}
int main(){
int arr[]={1,2,3,4};
int size=sizeof(arr)/sizeof(arr[0]);
printf("Array elements:\n");
printArray(arr,size,0);
return 0;
}









