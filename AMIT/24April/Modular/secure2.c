#include<stdio.h>

void main()
{
	int user_id = 1000000000; // May overflow on 32-bit sy
	user_id++; // Could become negative due to overflow
	if (user_id > 100) 
	{
	    printf("User id :%d\n",user_id);  	// Check might fail due to unexpected value
		                                 // Grant access (potentially unintended)
		}
}
