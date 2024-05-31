#include<stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <stdint.h>

#define DEVICE_NAME "/dev/usb_example"

int main(){

int fd;

char data[512];

fd=open(DEVICE_NAME, O_RDWR);

if(fd<0){

perror("Open");

return -1;

}

printf("Reading from USB device\n"); 
if(read(fd,data, sizeof(data))<0){

perror("Failed to read from USB device\n");

close(fd);

return -1;

}

printf("Reading from USB device is done and data is %s\n", data);

strcpy(data, "Namaste");

printf("Writing to USB Device %s\n", data);

if(write(fd,data, sizeof(data))<0){

perror("Falled to write to USB device\n");

close(fd);

return -1;

}

close(fd);

return 0;
}
