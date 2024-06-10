#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/temp_sensor"

int main()
{
	int fd;
	int temp;

	fd = open(DEVICE_PATH , O_RDONLY);

	if(fd < 0 )
	{
		perror("failed to open the device file");
		return -1;
	}

	if(read (fd , &temp , sizeof(int)) < 0)
	{
		perror("failed to read temperature from the device ");
		close(fd);
		return -1;
	}

	printf("temperature : %d\n" , temp);

	close(fd);
	return 0;
}

