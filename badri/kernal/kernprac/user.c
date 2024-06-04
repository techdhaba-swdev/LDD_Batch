#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/buffer"

int main()
{
char data [500];
int fd ;

printf("enter the string \n");
fgets(data , sizeof(data) , stdin);

fd = open(DEVICE_NAME , O_WRONLY);

if (fd < 0 )
{
	perror("error in opening file \n ");
	return -1;
}

if(write (fd , data , sizeof(data)))
printf("user msg : %s\n" ,data);


close(fd);

return 0;

}
