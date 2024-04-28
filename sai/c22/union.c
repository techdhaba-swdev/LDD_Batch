#include<stdio.h>

union value{
	char a;
	char b;
	char c;
	char d;
	char arr[4];
};

int main()
{
	union value charat;
	charat.a = 'A';
	charat.b = 'B';
	charat.c = 'C';
	charat.d = 'D';
	charat.a[0] = 's';
	charat.a[1] = 'd';
}

