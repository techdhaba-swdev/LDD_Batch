#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/add_values"

int main() {
    int fd;
    int value1, value2, result;

    printf("Enter an two integer values: ");
    scanf( "%d %d", &value1, &value2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }
	if(write(fd, &value1,sizeof(int)) != sizeof(int)){
			perror("failed to write value1");
			close(fd);
			return 1;
	}
	 if(write(fd, &value2,sizeof(int)) != sizeof(int)){
                        perror("failed to write value1");
                        close(fd);
                        return 1;
	 }
	 int buffer[2] = {value1, value2};
    // Write the input value to the device
    
    write(fd, buffer, 2*sizeof(int));

    // Read the doubled value from the device
    read(fd, &result, sizeof(int));

    printf("Result value received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}

