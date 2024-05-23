#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define DEVICE_PATH "/dev/add_device"
#define BUF_SIZE 256

int main() {
    int fd;
    int *kernel_buffer;
    int result;

    // Open the character device interface
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    // Map the kernel buffer to user space
    kernel_buffer = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (kernel_buffer == MAP_FAILED) {
        perror("Failed to map the buffer");
        close(fd);
        return -1;
    }

    // Write input operations to the mapped buffer
    sprintf((char *)kernel_buffer, "4+5");
    sleep(1); // Delay to allow kernel module to perform calculation
    result = *kernel_buffer;
    printf("Result of 4+5: %d\n", result);

    sprintf((char *)kernel_buffer, "4+6");
    sleep(1); // Delay to allow kernel module to perform calculation
    result = *kernel_buffer;
    printf("Result of 4+6: %d\n", result);

    // Unmap and close
    munmap(kernel_buffer, BUF_SIZE);
    close(fd);

    return 0;
}
