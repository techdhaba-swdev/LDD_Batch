#include<stdio.h>

int add(int num1,int num2){
	int result=num1+num2;
	return result;

}

int sub(int num1,int num2){
        int result=num1-num2;
        return result;

}

int mul(int num1,int num2){
        int result=num1*num2;
        return result;

}

int div(int num1,int num2){
        int result=num1/num2;
        return result;

}
int main(){

	int num1=20,num2=10;
	printf("sum is %d\n",add(num1,num2));
	printf("substraction is %d\n",sub(num1,num2));
	printf("multiplication is %d\n",mul(num1,num2));
	printf("division is %d\n",div(num1,num2));
	return 0;

}



