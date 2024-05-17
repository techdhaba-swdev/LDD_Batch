#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/sum_integer"

int main() {
    int fd;
    int num1,num2,result;

    printf("Enter an two integer value: ");
    scanf("%d%d", &num1,&num2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the input value to the device
    dprintf(fd,"%d %d", num1,num2);
   

    // Read the doubled value from the device
    read(fd, &result, sizeof(int));

    printf("Sum of the two number received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
