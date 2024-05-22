#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device_cal2"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    char operations[10][20] = {"4+3", "10+5", "6+8", "15+20", "7+7", "100+200", "30+40", "50+25", "12+18", "3+9"};
    char result_buffer[20];

    for (int i = 0; i < 10; i++) {
        // Write the operation to the device
        if (write(fd, operations[i], strlen(operations[i])) == -1) {
            perror("write");
            close(fd);
            return -1;
        }

        // Read the result from the device
        if (read(fd, result_buffer, sizeof(result_buffer)) == -1) {
            perror("read");
            close(fd);
            return -1;
        }

        // Print the result
        printf("Result from kernel space for operation %d: %s\n", i + 1, result_buffer);
    }

    close(fd);
    return 0;
}
