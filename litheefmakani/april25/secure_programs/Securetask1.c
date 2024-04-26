//input validation program 
//takes user input and checking within a specific range

#include<stdio.h>

int main(){
	int num;
	printf("ENter a number between 1 and 50: ");
	scanf("%d",&num);

	if(num >=1 && num <=50){
		printf("valid number entered:%d\n",num);
	}else{
		printf("Invalid number entered.\n");
	}
	return 0;
}

