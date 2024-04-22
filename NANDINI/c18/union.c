#include<stdio.h>

union charun
{
	char a;
	char b;
	char c;
	char d;
	char arr[5];
};
int main()
{
	union charun union1;
       	union1.arr[0] ='A';
	union1.arr[1] = 'B';
        union1.arr[2] = 'c';
	union1.arr[3] = 'D';
	printf(" a:%c\n",union1.a);
	printf(" b:%c\n",union1.b);
	printf(" c:%c\n",union1.c);
	printf(" d:%c\n",union1.d);
	printf(" array\n");
	for(int i=0;i<5;i++)
	{
		printf("%c",union1.arr[i]);
	}
	printf("\n");
	return 0;
}



