#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int num1,num2,result;
    int fd = open(DEVICE_PATH, O_RDWR); //called open and assigned to file descriptor fd
    if (fd < 0) {
        perror("open");
        return -1;
    }
    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); //called memmap system call from user program for mapping the devie in memory
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }
    //performing addition by taking input from user and returning to user and printing 
    printf("Enter values to add:");
    scanf("%d %d",&num1,&num2);
    int buffer[2]={num1,num2};
    write(fd,buffer,2*sizeof(int)); //calling write system call
    read(fd,&result,sizeof(int)); //calling read system call
    printf("After addition received from kernel: %d\n",result);
    // Example: Writing to the mapped memory
    strcpy((char *)mapped_memory, "Hello from user spacce!"); //storing the string into mapped memory variable by typecasting the variable
    //int x=(int *)mapped_memory;
    // Reading from the mapped memory and printing onto screen
    printf("Reading addition from device: %d\n", (int *)mapped_memory);

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}
