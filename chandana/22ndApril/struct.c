#include <stdio.h>
#include<stdlib.h>

int main() {
	union u {
		char a;
		char b;
		char c;
		char d;
		char arr[4];
	};
	union u u1;
       union u1.arr[0]='a';
       union u1.arr[1]='b';
	union u1.arr[2]='c';
	union u1.arr[3]='d';
	printf(" %c\n",u1.a);
        printf(" %c\n",u1.b);
        printf(" %c\n",u1.c);
	printf(" %c\n",u1.d);
	printf("size of union u1 is %d\n",sizeof(u1));
}
