#include<stdio.h>
void fun();
static int count=5;
int main(){
	
	while(count--){
		fun();
	}
	return 0;
}


void fun(){
	static int i=5;
	i++;
	printf("i is %d and count is %d\n",i,count);
}

