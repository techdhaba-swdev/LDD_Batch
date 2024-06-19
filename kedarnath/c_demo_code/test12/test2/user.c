#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h> 

#define DEVICE_NAME "/dev/chardev1"

int main(){

	int fd=open(DEVICE_NAME,O_RDWR);
	if(fd<0){
		printf("failed toopen file\n"); 
		return 0;

	}
	printf("fd is %d \n",fd); 

	close(fd);

	return 0;

}
