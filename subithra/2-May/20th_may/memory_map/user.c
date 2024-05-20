#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/memory_map", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    void *mapped_memory = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Use the mapped memory...

    if (munmap(mapped_memory, 4096) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}
