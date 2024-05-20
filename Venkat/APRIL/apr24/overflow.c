#include <stdio.h>
#include <limits.h>
int main() {
	int user_id = 10000000000;
	printf("from %d to %d\n",INT_MIN,INT_MAX);
	user_id++;
	if(user_id >100){
       printf("%d\n",user_id);
	}
}
