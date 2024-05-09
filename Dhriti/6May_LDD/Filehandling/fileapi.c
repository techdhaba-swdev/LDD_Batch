#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> //file control operations

 

int main() {
  char data[] = "This is some data to write to the file.\n";
  int fd;
  ssize_t bytes_written, bytes_read; //used for a count of bytes
  char buffer[100];

 

  // Open the file "my_file.txt" in read-write mode with create flag
  fd = open("my_file.txt", O_RDWR | O_CREAT, 0644); // ORDWR: reading n writing
						    // OCREAT: creates a file if it dosent exists
						    // 0664: reading n writing for owner and read only for others

 

  // Check if opening the file was successful
  if (fd == -1) {
    perror("open");
    return 1;
  }

 

  // Write data to the file
  bytes_written = write(fd, data, sizeof(data));

 

  if (bytes_written == -1) {
    perror("write");
    close(fd);
    return 1;
  }

 

  printf("Successfully wrote %ld bytes to the file.\n", bytes_written);

 

  // Seek to the beginning of the file for reading
  lseek(fd, 0, SEEK_SET);

 

  // Read data from the file
  bytes_read = read(fd, buffer, sizeof(buffer));

 

  if (bytes_read == -1) {
    perror("read");
    close(fd);
    return 1;
  }

 

  // Print the read data
  printf("Read %ld bytes from the file:\n%s\n", bytes_read, buffer);

 

  // Close the file
  close(fd);

 

  return 0;
}
