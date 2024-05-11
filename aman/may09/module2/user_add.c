#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#define DEVICE_PATH "/dev/integer_add"

int main()
{
	int fd;
	char buffer[256];

	fd = open(DEVICE_PATH, O_RDWR);
	if (fd < 0)
	{
		perror("Failed to open the device...");
		return errno;
	}

	printf("Enter two numbers separated by a space: ");
	scanf("%[^\n]%*c", buffer);

	if (write(fd, buffer, strlen(buffer)) < 0)
	{
		perror("Failed to write to the device...");
		return errno;
	}

	printf("Result from kernel: ");
	if (read(fd, buffer, 256) < 0)
	{
		perror("Failed to read from the device...");
		return errno;
	}
	printf("%s\n", buffer);

	close(fd);
	return 0;
}
