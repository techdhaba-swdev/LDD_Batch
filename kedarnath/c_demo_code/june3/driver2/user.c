#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define LED_DEV "/dev/led_device" 

int main(int argc, char *argv[]) {
    int fd, ret;
    char value;

    if (argc != 2 || (argv[1][0] != '0' && argv[1][0] != '1')) {
        fprintf(stderr, "Usage: %s <0|1>\n", argv[0]);
        return 1;
    }

    // Open the device file
    fd = open(LED_DEV, O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write the LED state
    value = argv[1][0] - '0';
    ret = write(fd, &value, sizeof(value));
    if (ret < 0) {
        perror("write");
        close(fd);
        return 1;
    }

   printf("LED state is: %d\n", value);


    // Read the current LED state
    ret = read(fd, &value, sizeof(value));
    if (ret < 0) {
        perror("read");
        close(fd);
        return 1;
    }
    
    if(value==0){
	    printf("LED is off\n");
    }else{
	    printf("LED is on\n"); 

    }
    printf("LED state is: %d\n", value);

    close(fd);
    return 0;
}




