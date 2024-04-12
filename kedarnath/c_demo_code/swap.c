#include<stdio.h>
int swap(int *num1,int *num2){
	int temp=*num1;
	*num1=*num2;
	*num2=temp;

}

int main(){

	int num1=100,num2=200;
	printf("before swap num1 is %d and num2 is %d\n",num1,num2);
	swap(&num1,&num2);
	printf("after swap num1 is %d and num2 is %d\n",num1,num2);

	return 0;

}
