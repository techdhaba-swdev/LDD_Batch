#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
	int fd ;
	ssize_t bytes;
	char buffer[1024];
	char file_read[1024];

	fd = open("example.txt", O_RDONLY);
	bytes = read(fd , buffer, BUFFER_SIZE -1 );
	printf("%s",buffer);
	close(fd);
	return 0;
}

