#include<stdio.h>

int searcharray(int array[], int size, int search)
{
	for(int i =0;i<size;i++){
		if(array[i] == search) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[] = {1,2,3,4,5,6,8);
		int size = sizeof(arr) / sizeof(array[0]);
		int search,index;

		printf("Eneter the element to search: ");
		scanf("%d",&search);

		index = searcharray(array, size, search);

		if(index != -1){
			printf("Element is Present")}
		else { 
			printf("Element is Present")}
   
		return 0;
	}
}
