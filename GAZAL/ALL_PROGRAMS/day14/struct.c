#include<stdio.h>
int main(){

union new1{
	char a;
	char b;
	char c;
	char arr[4];
}
union new1 new2;
	new2.a='ANYA';
	new2.b='bangkok';
	new2.c='cinaamon';
	printf("value of a:%d",new2.a);
	 printf("value of b:%d",new2.b);
	  printf("value of c:%d",new2.c);


}
