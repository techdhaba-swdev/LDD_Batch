#include<stdio.h>

int main() {
	int user_id = 1000000000;
	user_id++;
	if(user_id > 100) {
		printf("access granted.\n");
	}else{
		printf("access denied.\n");
	}
	return 0;
}

