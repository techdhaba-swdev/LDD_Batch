#include<stdio.h>
#include<stdlib.h>
int main(){
	int user_id=100;
	user_id++;
	if(user_id>100){
		printf("acess granted\n");
		int *ptr = (int*)malloc(sizeof(int));
		if(ptr == NULL){
			printf("Memory allocation failed\n");
			return -1;
		}
		*ptr=42;
		printf("value at allocated memory :%d\n",*ptr);
		free(ptr);
	}else{
		printf("acess denied\n");
	}
	return 0;
}
