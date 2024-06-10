#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/ioctl"
#define IOCTL_MAGIC 'k'
#define IOCTL_add _IOWR(IOCTL_MAGIC , 1 , struct ioctl *)
#define IOCTL_sub _IOWR(IOCTL_MAGIC , 2 , struct ioctl *)

struct ioctl
{
	int num1;
	int num2;
}data;

int main()
{
	int fd;
	fd = open(DEVICE_NAME , O_RDWR);

	if(fd < 0)
	{
		perror("error in opening file \n ");
		return -1;
	}
	data.num1 = 10;
	data.num2 = 20;

	if (ioctl(fd , IOCTL_add , &data) < 0)
	{
		perror("ioctl add failed \n");
		close(fd);
		return -1;
	}

 	if (ioctl(fd , IOCTL_sub , &data) < 0)
        {       
                perror("ioctl sub failed \n");
		close(fd);
                return -1;
        }       
printf("sum of num is %d\n" , sum);
printf("sub of num is %d\n" , sub );

close(fd);
return 0;
}
