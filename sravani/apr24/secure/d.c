#include<stdio.h>
#include<stdlib.h>
int main(){
	int* ptr=(int*)malloc(sizeof(int));//ptr is allocated
	*ptr=30;
	printf("%d\n:",ptr);
	free(ptr);//pointer is delocated
	*ptr=42;
	printf("%d\n:",ptr);
	return 0;
}

