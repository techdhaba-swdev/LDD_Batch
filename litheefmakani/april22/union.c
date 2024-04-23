#include<stdio.h>
#include<string.h>

union Charunion {
	char a;
	char b;
	char c;
	char d;
};
int main(){
	union Charunion myUnion;
	char arr[4];
	myUnion.a='L';
	myUnion.b='I';
	myUnion.c='T';
	myUnion.d='H';


	arr[0]='E';
	arr[1]='E';
	arr[2]='F';
	arr[3]='M';

	printf("union variables are :\n");
	printf("a: %c\n",myUnion.a);
	printf("b: %c\n",myUnion.b);
	printf("c: %c\n",myUnion.c);
	printf("d: %c\n",myUnion.d);

	printf("\n Array of elements are:\n");
	for(int i=0;i<4;i++){
		printf("arr[%d]: %c\n", i,arr[i]);
	} 
	return 0;
}
