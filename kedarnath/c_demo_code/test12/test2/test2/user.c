#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define DEVICE_NAME "/dev/chardev2"


int main(){

	int fd;
	char buffer_read[100];
	fd=open(DEVICE_NAME,O_RDWR);

	printf("value fd is %d\n",fd);

	ssize_t byte_read=read(fd,buffer_read,sizeof(buffer_read));
	printf("byte read is %d\n",byte_read);
	printf("data is %s\n",buffer_read);  

	close(fd);

	return 0;

} 

