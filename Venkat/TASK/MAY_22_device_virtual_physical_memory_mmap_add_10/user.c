#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/my_device"
#define DEVICE_MEMORY_SIZE 4096 // 4KB
#define NUM_COUNT 10
int main() {
   int nums[NUM_COUNT];
   int sum = 0;
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

  

    // inputing 10 numbers 
    printf("enter the integer\n");
    for(int i =0;i< NUM_COUNT; i++) {
	    scanf("%d",&nums[i]);
    }
    char buffer[sizeof(int)*NUM_COUNT+sizeof(char)]; 
   
  for(int i = 0; i<NUM_COUNT;i++) {
            memcpy(buffer+ i * sizeof(int),&nums[i],sizeof(int)); // each integer is from num array is placing in buffer like page/table 
   } memcpy(buffer + sizeof(int) * NUM_COUNT, "+", sizeof(char)); // buffer[0] = num[0] // Write the to buffer every time left shift 
     // allocating memory for each number arranged through loop in page/table 1,2,3 with like 001 for first number left shift page/table array 001 << to 0010 after one iterate loop it will arrange memeory 
                                                                  // 
    if (write(fd, buffer, sizeof(int) * NUM_COUNT+sizeof(char)) < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Read the result from the device
    int result;
  //  if (read(fd, &result, sizeof(result)) < 0) {
   if (read(fd,&sum, sizeof(sum)) < 0) {
        perror("read");
        close(fd);
        return -1;
    }

    printf("Sum of %d numbers is %d\n",NUM_COUNT,sum);

    close(fd);
    return 0;
}
