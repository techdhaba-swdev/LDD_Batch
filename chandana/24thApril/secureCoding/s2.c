#include <stdio.h>
int main(){
int user_id=1000000000;//May overflow on 32-bit system
user_id++;//COuld becoome negative due to overflow
if(user_id > 100){//Check might fail due to unexpected value
printf("Access granted\n");
}else{
	printf("Access denied\n");
}
return 0;
}

//Initialize user_id to a very large value
//Increment user_id by 1
//Grant access (potentially unintented)


