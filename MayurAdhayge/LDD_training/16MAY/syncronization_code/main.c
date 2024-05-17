#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include<pthread.h>
#define DEVICE_NAME "/dev/data_transfer_part_2"
#define DATA_SIZE sizeof(struct user_data)

void *data_transfer_to_kernel(int *fd,struct user_data *data,int size);

struct user_data {
  int value;
  char message[100];
};

void *data_transfer_to_kernel(int *fd,struct user_data *data,int size)
{
int  ret;

ret = write(*fd, &data, size);
  
  if (ret != size) {
    perror("Failed to write data");
    close(*fd);
    exit(1);
  }

  printf("Data sent successfully!\n");
}

int main() {
  pthread_t t[3];
  int fd;
  struct user_data data[3];

  // Open the device
  fd = open(DEVICE_NAME, O_WRONLY);
  if (fd == -1) {
    perror("Failed to open device");
    exit(1);
  }
 for (int i=0;i<3;i++)
 {
  // Prepare data to send
  data[i].value = 42+i;
 snprintf(data[i].message, sizeof(data[i].message), "%d hello",i);
  // Send data to the kernel
  pthread_create(&t[i],NULL,data_transfer_to_kernel,&fd,&data[i],DATA_SIZE);
}

 for (int j=0;j<3;j++)
 {
  pthread_join(t[j],NULL);
 }
  // Close the device (optional, as the program exits)
  close(fd);

  return 0;
}
