#include<stdio.h>
#include<sys/ioctl.h>
#include<string.h>
#include<fcntl.h>

#define WR_DATA _IOW('k','0',char *)
#define RD_DATA _IOR('k','1',char *)

int main(){
	int fd;
	char user_buff[100];
	char buff[100];
	fd=open("/dev/char_ioctl",O_RDWR);
	printf("\n\n..........IOCTL BASED CHAR DEVICE DRIVER FROM USER SPACE..........\n");
	if(fd<0){
		printf("Device opening unsuccessfull\n");
		return -1;
	}
	printf("\nEnter string to send to char ioctl driver:");
	scanf("%s",user_buff);
	printf("\n\n.....Just a second writing Message to DRIVER.....\n\n");
	ioctl(fd,WR_DATA,&user_buff);
	printf(".....Reading message from DRIVER.....\n\n");
	ioctl(fd,RD_DATA,&buff);
	printf("DATA from kernel is %s\n\n",buff);
	printf(".....CLOSING DRIVER.....\n\n");
	close(fd);
	return 0;
}
