#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int reversedarray(int arr[], int size)
{
	int first = 0;
	int last = size -1;

	while(first<last){
		swap(&arr[first], &arr[last]);
		first++;
		last--;
	}
}

int main(){
	int arr[] = {1,2,3,4,5,6,7};
	int size = sizeof(arr)/ sizeof(arr[0]);

	printf("Array: ");

	reversedarray(arr,size);

	printf("\nReversed array: ");
	for(int i=0;i<size;i++){
		printf("%d", arr[i]);
	}

	return 0;
}

