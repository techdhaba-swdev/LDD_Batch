#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define DEVICE_NAME "/dev/mychardev"
int main(){
	int fd;
	char buffer[100];

	fd=open(DEVICE_NAME,O_RDWR);
	if(fd==-1){
		perror("open");
		return 1;
	}
	ssize_t bytes_read=read(fd,buffer,sizeof(buffer));
	if(bytes_read<0){
		perror("read");
		close(fd);
		return 1;
	}
	printf("\nRecieved Data from kernel is %s\n",buffer);
	close(fd);
	return 0;
}
