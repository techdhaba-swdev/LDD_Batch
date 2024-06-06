#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define DEVICE_PATH "/dev/simple_char_driver"
#define length 100
int main(){
	int fd;
	char buff[]="Namasthe Mere jaan";
	char read_buff[1024];
	fd=open(DEVICE_PATH,O_RDWR);
	if(fd<0){
		printf("Cannot open device");
		return -1;
	}
	write(fd,buff,strlen(buff)+1);
	read(fd,read_buff,1024);
	printf("Data from kernel is %s\n",read_buff);
	close(fd);
	return 0;
}


