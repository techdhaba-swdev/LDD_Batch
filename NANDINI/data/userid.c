#include<stdio.h>
int main()
{
	int user_id = 10000000;
        user_id++;
	if(user_id > 100)
	{
           puts("GRAND ACCESS");
	}
	else
	{
           puts("DENY ACCESS");
	}

	return 0;
}

