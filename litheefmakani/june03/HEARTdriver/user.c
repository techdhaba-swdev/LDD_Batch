#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd;

  fd = open("/dev/heart_dev", O_RDWR);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Simulate reading heart rate (driver should provide actual data)
  printf("Heart rate: (read from driver)\n");

  close(fd);
  return 0;
}
