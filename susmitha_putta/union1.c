#include<stdio.h>

union chars {
	char a;
	char b;
	char c;
	char d;
	char arr[4];
};

int main()
{
	union chars Union = {'1','2','3','4'};
	printf("a: %c\n", Union);
	printf("b: %c\n", Union);
	printf("c: %c\n", Union);
	printf("d: %c\n", Union);

	return 0;
}


