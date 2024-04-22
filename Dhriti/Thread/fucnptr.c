#include<stdio.h>
int add(int x, int y);
int sub(int x, int y);
int main(){
	int (*fp)(int int) = add;
	printf(" add is %d \n" fp(4,3));
	fp = sub;
	printf(" sub is %d \n" fp(4,3));
	return 0;
}

int add(int x, int y){
	return x+y;
}
int sub(int x, int y){
	return x-y;
}
