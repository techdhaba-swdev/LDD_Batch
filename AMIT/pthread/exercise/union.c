#include<stdio.h>
#include<string.h>


union name
{
	char a;
	char b;
	char c;
	char d;
	char arr[4];
};

int main()
{
	union name name1;
        name1.a='A';
	 printf("name1 =%s\n",name1.a);

	name1.b='B';
	 printf("name2 =%s\n",name1.b);

	name1.c='C';
	 printf("name3 =%s\n",name1.c);

	name1.d='D';
	 printf("name4 =%s\n",name1.d);

	strcpy(name1.arr,"amit");

	printf("name5 =%s\n",name1.arr);

	printf("size of union %d \n",sizeof(name));
}



