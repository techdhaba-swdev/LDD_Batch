#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
	int src_fd,des_fd;
	char buffer[BUFFER_SIZE];
	src_fd=open("example.txt",O_RDONLY);
	if(src_fd<0){
		perror("error opening file\n");
		return 1;
	}
	des_fd=open("dest.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
	if(des_fd<0){
                perror("error opening file\n");
                return 1;
        }
	ssize_t bytes_read=read(src_fd,buffer,BUFFER_SIZE-1);
	ssize_t bytes_written=write(des_fd,buffer,bytes_read);
	close(src_fd);
	close(des_fd);
	return 0;
}

