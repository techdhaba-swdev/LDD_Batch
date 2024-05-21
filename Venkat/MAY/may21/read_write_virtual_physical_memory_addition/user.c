#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define DEVICE_PATH "/dev/my_device"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd;
    void *mapped_memory;
    int numbers[2] = {10, 20};
    int result;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

   
    mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("Failed to map the device memory");
        close(fd);
        return -1;
    }

    
    memcpy(mapped_memory, numbers, sizeof(numbers));
    printf(" numbers written to the device memory :%d,%d\n",numbers[0],numbers[1]);
   
    if (read(fd, &result, sizeof(result)) == -1) {
        perror("Failed to read from the device");
        munmap(mapped_memory, MEMORY_SIZE);
        close(fd);
        return -1;
    }

    printf("Result of addition: %d\n", result);

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("Failed to unmap the device memory");
    }
    close(fd);
    return 0;
}
