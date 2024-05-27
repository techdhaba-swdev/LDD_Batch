#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/char_device"

int main(){
	int fd;
	char w[] = "good morning";
	char r[1024] ={0};

	fd = open(DEVICE_PATH, O_RDWR);
	if(fd < 0) {
		perror("failed");
		return EXIT_FAILURE;
	}

	//write to device
	write(fd,w,sizeof(w));
	printf("string in buffer is %s\n",w);
//read from the device
	read(fd,r,sizeof(r));
	printf("string to read is %s\n",r);

	close(fd);
	return 0;
}
