#include<stdio.h>

union sampleunion 
{
	char a;
	char b;
	char c;
	char d;
	char arr[4];
};
int main()
{
	union sampleunion sample;

	sample.arr[0] = 'A';
	sample.arr[1] = 'B';
	sample.arr[2] = 'C';
	sample.arr[3] = 'D';


	printf("value of a: %c\n", sample.a);
	printf("value of b: %c\n", sample.b);
	printf("value of c: %c\n", sample.c);
	printf("value of d: %c\n", sample.d);

	printf("values of arr: %c %c %c %c\n", sample.arr[0], sample.arr[1], sample.arr[2], sample.arr[3]);

	printf("size of the union :%lu bytes\n",sizeof(sample));
	return 0;
}
