#include<stdio.h>
#include<stdlib.h>
int main(){
	int user_id = 100000;
	user_id++;

	if(user_id >1000000){
		printf("acess granted\n");
	}else{
		printf("acees denied\n");
	}
}
