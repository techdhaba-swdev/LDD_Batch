#include<stdio.h>
void swap(int *a,int *b){
	int temp =*a;
	*a =*b;
	*b=temp;
}
int main() {
	int num1=5;
	int num2=10;
	printf("before swapping: num1= %d,num2=%d\n",num1,num2);
	swap(&num1,&num2);
	printf("after swapping: num1= %d,num=%d\n",num1,num2);
	return 0;
}
