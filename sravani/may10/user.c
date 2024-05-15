#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define DEVICE_NAME "/dev/reverse_string"
#define MAX_LENGTH 100
#define IOCTL_REVERSE_STRING _IOWR('r', 1, char[MAX_LENGTH])

int main() {
    int fd;
    char input_string[MAX_LENGTH];
    char reversed_string[MAX_LENGTH];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    printf("Enter a string to reverse: ");
    fgets(input_string, MAX_LENGTH, stdin);

    // Write the input string to the device write(fd, input_string, strlen(input_string));
	if(write(fd,input_string,strlen(input_string)) < 0){
		perror("Failed to write t device");
		close(fd);
		return 1;
	}
    // Read the reversed string from the device using IOCTL
        if(ioctl(fd, IOCTL_REVERSE_STRING, reversed_string) <0){
		perror("ioctl failed");
		close(fd);
		return 1;
	}

    printf("Reversed string received from device using IOCTL: %s\n", reversed_string);

    // Close the device file
    close(fd);

    return 0;
}
