#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
        int fd;
        char buffer[BUFFER_SIZE];
        fd=open("example.txt",O_RDONLY);
        if(fd<0){
                perror("error opening file\n");
                return 1;
        }
        ssize_t bytes_read=read(fd,buffer,BUFFER_SIZE-1);
	printf("%s\n",buffer);
        close(fd);
        return 0;
}

