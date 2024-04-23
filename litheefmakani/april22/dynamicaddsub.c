#include<stdio.h>
void lib_handle(){
	int  add(int  a, int  b){
		return a+b;
	}
	int  sub(int  a, int  b){
		return a-b;
	}
	int  mul(int  a, int  b){
		return a * b;
	}
	float div(float a, float b){
		if(b==0){
			printf("Error : Division by zero\n");
			return 0;
		}else{
			return a / b;
		}
	}
}

