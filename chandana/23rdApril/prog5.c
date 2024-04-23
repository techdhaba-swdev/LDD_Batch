#include <stdio.h>

int add(int a,int b) {
	return a+b+2;
}
int sub(int a,int b){
	return a-b+2;
}
int mul(int a,int b){
	return a*b;
}
int div(int a,int b){
	if(b!=0){
		return a/b;
	}
	else{
		printf("Error Division by zero\n");
		return 0;
	}
}

