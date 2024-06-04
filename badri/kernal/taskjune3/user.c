#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/multiple"
int main()
{
	int fd , value ;
	int res;

	printf("enter the valueto get its multiples  \n");
	scanf("%d", &value);
	
	fd = open (DEVICE_NAME , O_RDWR);
	if(fd < 0)
	{
		perror("error in opening file descriptor \n");
		return -1;
	}
	
	write (fd , &value , sizeof(int));
	read (fd , &res , sizeof(int));

	printf("the result of entered value %d\n" , res);

	close(fd);
	return 0;
}

