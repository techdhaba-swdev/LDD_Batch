#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define DEVICE_NAME "/dev/chardev4"

int main(){

	int fd;
	char buffer[100];
	fd=open(DEVICE_NAME,O_RDWR);
	if(fd<0){
		printf("device failed to open\n");
		return 0;
	}

	printf("value of fd is %d\n",fd);

	ssize_t byte_read=read(fd,buffer,sizeof(buffer));
	printf("value of byte readed is %d\n",byte_read);
	printf("%s\n",buffer);

	close(fd);
	return 0;

}  

