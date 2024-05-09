#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define DEVICE_NAME "swap"

int main(){
	int fd;
	int a;
	int b;
	// Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }
	printf("Enter two values : ");
	scanf("%d %d",&a,&b);
	dprintf(fd,"%d %d",a,b);

	int swapped_a, swapped_b;
	read(fd,&swapped_a,sizeof(int));
	read(fd,&swapped_b,sizeof(int));
	printf("Swapped values received from device a==%d , b=%d\n",swapped_a,swapped_b);

	close(fd);
	return 0;
}
