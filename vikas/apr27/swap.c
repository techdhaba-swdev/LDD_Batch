#include<stdio.h> //standard input and output header

int main() {

	int a=10;
	int b=20;
	int swap;

	//printing values before swapping
	printf("before swapping the values of\n a:%d b:%d\n",a,b);

	//perform swap opertion
	swap=a;
	a=b;
	b=swap;

	//printing values after swapping
	printf("after swapping the values of\n a:%d b:%d\n",a,b);

	return 0; //successfull completion of program
}
