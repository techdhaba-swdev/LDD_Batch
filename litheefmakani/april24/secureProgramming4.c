#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr = (int*)malloc(sizeof(int));//allocationg memory
	printf("address of ptr:%d\n",*ptr);
	free(*ptr);
	printf("address of ptr: %d\n",*ptr);
	*ptr=34;
	printf("value is stored: %d\n",*ptr);
}
