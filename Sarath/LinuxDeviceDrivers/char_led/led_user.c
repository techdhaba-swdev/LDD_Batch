#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define LED_DEV "/dev/led_dev"

int main(int argc, char *argv[]) {
    int fd, ret;
    char choice,read_choice;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <0|1>\n", argv[0]);
	fprintf(stderr, "colour code : 0(off),1(on),2(red),3(green),4(blue)\n");
        return 1;
	}
    choice=atoi(argv[1]); //coverting char to integer using atoi
    // Open the device file
    
    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
	return 1;
    }
    //choice=argv[1][0];
    ret=write(fd,&choice,sizeof(choice));
    if(ret<0){
	    perror("Failed to write to device");
	    return 1;
    }
    read(fd,&read_choice,sizeof(read_choice));
    printf("Sent colour code %d to led driver\n",choice);
    if(read_choice==0){

    printf("Read colour code from kernel %d which is off \n",(int)read_choice);
    }
    else{
	    printf("Read colour code from kernel %d   which is on\n",(int)read_choice);
    }
    close(fd);
    return 0;
}
