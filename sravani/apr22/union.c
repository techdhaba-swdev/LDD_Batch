#include<stdio.h>
union charun{
	char a;
	char b;
	char c;
	char d;
	char arr[4];
};
int main(){
	union charun union1; 
	union1.arr[0]='b';
	union1.arr[1]='t';
	union1.arr[2]='s';
	union1.arr[3]='D';
	printf("%c\n",union1.a);
	printf("%c\n",union1.b);
	printf("%c\n",union1.c);
	printf("%c\n",union1.d);
	printf("array\n");
	for(int i=0;i<4;i++){
		printf("%c",union1.arr[i]);
	}
	printf("\n");
	return 0;
}

