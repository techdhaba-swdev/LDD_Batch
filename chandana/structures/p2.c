#include <stdio.h>
#include <stdlib.h>

int* allocateIntArray(int size){
	int* arr = (int*)malloc(size * sizeof(int));

	if(arr==NULL){
		printf("memeory alloaction failed.\n");
		exit(1);
	}
	return arr;
}

int main(){
	int size;

	printf("enter the size of thr array:");
	scanf("%d",&size);

	int* arr = allocateIntArray(size);

	printf("Memeory address of array elements:\n");
	for(int i=0;i<size;i++) {
		printf("%p\n",(void*)&arr[i]);
	}
	free(arr);
	return 0;
}
