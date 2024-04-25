#include<stdio.h>
#include<stdlib.h>
int main()
{
	int user_id=100000000000000000000;
	user_id++;
	if(user_id>100)
	{
		printf("id: %d\n",user_id);	
	}
	printf("id:%d\n",user_id);
}

