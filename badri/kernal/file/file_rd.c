#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILE_NAME "badri.txt"
#define BUFFER_LEN 1000

int main()
{
	int fd;
	ssize_t bytes_read;
	char buffer[BUFFER_LEN];
	fd = open(FILE_NAME , O_RDONLY);
	
	if(fd == -1)
	{
		perror("failed to open file for reading\n");
		
		exit(EXIT_FAILURE);
	}
	(bytes_read = read(fd , buffer , BUFFER_LEN -1)) ;

	if(bytes_read == -1)
	{
		perror("failed to read from file\n");
		close(fd);
		exit(EXIT_FAILURE);
	}

	buffer[bytes_read] = '\0';

	printf("read %zd bytes from the filw : \n %s \n",bytes_read,buffer);

	if(close(fd) == -1)
	{
		perror("failed to close the file\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
