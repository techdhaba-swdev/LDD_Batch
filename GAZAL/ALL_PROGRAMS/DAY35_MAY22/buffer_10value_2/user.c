#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/buffers_add"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    int num1, num2, result;
    char operation = '+';
    char buffer[sizeof(int) * 2 + sizeof(char)];

    // declaring first number
    num1 = 1;

    // loop to add numbers from 2to10
    for (num2 = 2; num2 <= 10; ++num2) {
       
        memcpy(buffer, &num1, sizeof(int));
        memcpy(buffer + sizeof(int), &num2, sizeof(int));
        memcpy(buffer + sizeof(int) * 2, &operation, sizeof(char));

        // wrt the buffer
        if (write(fd, buffer, sizeof(buffer)) < 0) {
            perror("write");
            close(fd);
            return -1;
        }

        // eading result from device
        if (read(fd, &result, sizeof(result)) < 0) {
            perror("read");
            close(fd);
            return -1;
        }

        // updating num1 
        num1 = result;
    }

   
      printf("Calculating 1+2+3+4+5+6+7+8+9+10\n");

    printf("Calculation result: %d\n", result);

    close(fd);
    return 0;
}
