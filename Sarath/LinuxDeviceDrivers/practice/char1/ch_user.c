#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define DEVICE_PATH "/dev/ch_device"
int main(){
	int fd;
	char option;
	int8_t  buff[1024];
	int8_t read_buff[1024];
	fd=open(DEVICE_PATH,O_RDWR);
	if(fd<0){
		printf("Cannot open device");
		return 0;
	}
	while(1){
		printf("\n\nWelcome to CHARACTER DEVICE DRIVER");
		printf("\n----------Enter option----------\n");
		printf("          1.WRITE          \n");
		printf("          2.READ          \n");
		printf("          3.EXIT          \n");
		scanf("%c",&option);

		switch(option){
			case '1':
				printf("Enter the string to write:");
				scanf("%s",buff);
				write(fd,buff,strlen(buff)+1);
				printf("\n.......Writing Done.......\n");
				break;
			
			case '2':
				printf(".......Reading done.......\n");
				read(fd,read_buff,1024);
				printf("Data written : %s\n",read_buff);
				break;
			
			case '3':
				close(fd);
				exit(1);
				break;
			
		/*	default:
				printf("Enter valid option\n");
				break;
		*initialization of ‘ssize_t (*)(struct file *, char *, size_t,  loff_t *)’ {aka ‘long int (*)(struct file *, char *, long unsigned int,  long long int *)’} from incompatible pointer type ‘ssize_t (*)(struct file *, char *, ssize_t,  loff_t *)’ {aka ‘long int (*)(struct file *, char *, long int,  long long int *)/		
		}
	}
	close(fd);
	return 0;
}
