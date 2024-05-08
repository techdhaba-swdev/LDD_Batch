#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char data[] = "This is some data to write to the file.\n";
	int fd;
	ssize_t bytes_written,bytes_read;
	char buffer[100];
	//open the file "myfile.txt" in read-write mode with create flag
	fd = open("myfile.txt" , O_RDWR | O_CREAT , 0644);
	//CHECK IF OPENING THE FILE WAS SUCCESSFUL
        if(fd == -1)
	{
		perror("open");
		return 1;
	}
	//write the data to the file
	bytes_written = write (fd , data , sizeof(data));

	if (bytes_written == -1)
	{
		perror("write");
		close(fd);
		return 1;
	}
	printf("successfully wrote %ld bytes to the file.\n",bytes_written);
	//seek to the begining of the file for reading
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

