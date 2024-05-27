#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	int source_fd, des_fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_written, bytes_read;
	// opening the source file
	source_fd = open("example.txt", O_RDONLY);
	if (source_fd == -1)
	{
		perror("error opening the fiel");
		return 1;
	}
	des_fd = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);
	if (des_fd == -1)
	{
		perror("error opening the file ");
		return 1;
	}
	bytes_read = read(source_fd, buffer, BUFFER_SIZE -1);
	bytes_written = write(des_fd, buffer, bytes_read);
	close(source_fd);
	close(des_fd);
	return 0;
}

