#include<stdio.h>
static void privateFunction();
int main(){
	privateFunction();
	return 0;
}
static void privateFunction(){
	printf("this is private function\n");
}
