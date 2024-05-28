#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FILENAME "example.txt"
#define BUFFER_SIZE 1024

int main()
{
	int fd;
	ssize_t bytes_written,bytes_read;
	char buffer[BUFFER_SIZE];

	fd=open(FILENAME,O_WRONLY| O_CREAT | O_TRUNC ,S_IRUSR | S_IWUSR);
	if(fd==-1)
	{
		perror("failed to open file for writing");
		exit(EXIT_FAILURE);
	}

	const char *data_to_write ="hello, world ! \n this is the test file.\n";
	bytes_written= write(fd,data_to_write,strlen(data_to_write));

	if(bytes_written==-1)
	{
		perror("failed to write the file");
		close(fd);     
	       	exit(EXIT_FAILURE);
	}

	printf("Wrote %zd bytes to the file.\n",bytes_written);

	if(close(fd)==-1)
	{
		perror("failed to close the file after writing");
		exit(EXIT_FAILURE);
	}

	fd=open(FILENAME , O_RDONLY);
	if(fd==-1)
        {
                perror("failed to OPEN  file FOR  reading");
                exit(EXIT_FAILURE);
        }

	bytes_read=read(fd,buffer,BUFFER_SIZE-1);
	 if(bytes_read==-1)
        {
                perror("failed to read from the file");
                close(fd);
                exit(EXIT_FAILURE);
        }

	buffer[bytes_read]='\0';
	printf("Read %zd bytes from the file:\n %s \n" ,bytes_read,buffer);

	 if(close(fd)==-1)
        {
                perror("failed to close the file after reading");
                exit(EXIT_FAILURE);
        }

	 return 0;
}














