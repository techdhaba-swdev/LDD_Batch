#include<stdio.h>
int findLargest(int arr[],int size){
	int largest = arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>largest){
			largest=arr[i];
		}
	}
	return largest;
}
int findSmallest(int arr[], int size){
	int smallest  = arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]<smallest){
			smallest = arr[i];
		}
	}
	return smallest;
}
int main()
{
	int arr[]= {1,2,3,4,5,6,7,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	int largest = findLargest(arr,size);
	int smallest = findSmallest(arr,size);
	printf("largest:%d\n",largest);
	printf("smallest:%d\n",smallest);
	return 0;
}
