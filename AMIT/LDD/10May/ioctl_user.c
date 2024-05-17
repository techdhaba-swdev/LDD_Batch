#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

//#define DEVICE_PATH "/dev/string_char_dev"

#define IOCTL_SET_MSG _IOW('q', 1, char *)      //define the IOCTL_SET_MSG 

//'q' > arbitary identifier , '1' > indicates command number , 'char*' > type of the data expected by driver



int main() {
    int fd;
    char message[100] = "New message for the driver";   //char array containing message

    fd = open("/dev/simple_char_driver", O_RDWR);    //file descripter to interact with device file 
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    ioctl(fd, IOCTL_SET_MSG, message);  //ioctl system call is used to send control command to driver
                                        //here  uses ioctl to send message to driver using IOCTL_SET_MSG
    close(fd);
    return 0;
}

