//safe dynamic memory allocation 
//dynamically allocates memory for an array.

#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arr;
	int size;

	printf("Enter size of array: ");
	scanf("%d",&size);

	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL){
		printf("Memory allocation failed.\n");
		return 1;
	}
	//use the allocated memory
	
	free(arr); //free allocated memory when done

	return 0;
}
