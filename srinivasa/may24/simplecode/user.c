#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define DEVICE_PATH "/dev/simple_chardev"

int main()
{
	int fd;
	char message[50] = " hello , this is srinu";
	char message_read[50];

	fd = open(DEVICE_PATH, O_RDWR);
	if (fd < 0)
	{
		perror(" failed to open the device");
		return 1;
	}

	write(fd,message, sizeof(message));
	printf("message writen to kernal space\n");
	read(fd,message_read, sizeof(message_read));
	printf("message read from the kernal : %s",message_read);
	close(fd);
	return 0;
}


