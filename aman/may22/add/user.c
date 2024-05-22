#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/addition"
#define ADD_COUNT 10

int main() {
    int fd;
    int *shared_mem;
    int input[ADD_COUNT][2] = {
        {3, 3}, {2, 3}, {3, 4}, {3, 6}, {3, 7},
        {3, 8}, {3, 10}, {3, 2}, {3, 7}, {3, 8}
    };

    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    shared_mem = mmap(NULL, 2 * ADD_COUNT * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_mem == MAP_FAILED) {
        close(fd);
        perror("mmap failed");
        return 1;
    }

    for (int i = 0; i < ADD_COUNT; i++) {
        shared_mem[2 * i] = input[i][0];
        shared_mem[2 * i + 1] = input[i][1];
    }

    for (int i = 0; i < ADD_COUNT; i++) {
        printf("Result of addition (%d + %d): %d\n",
               shared_mem[2 * i], shared_mem[2 * i + 1], shared_mem[2 * i] + shared_mem[2 * i + 1]);
    }

    munmap(shared_mem, 2 * ADD_COUNT * sizeof(int));
    close(fd);
    return 0;
}
