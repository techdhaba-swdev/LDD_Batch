#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> //file control options
#include<unistd.h>


#define BUFF_SIZE 1000

int main() {
	int src_file, dest_file;
	ssize_t bytes_read, bytes_write;
	char buffer[BUFF_SIZE];


	//Open source file for reading
        src_file = open("src.txt", O_RDONLY | O_CREAT, 0664 );
	if(src_file == -1) {     //-1: opening src file is failed

		perror("Error opening src file");
		return EXIT_FAILURE;
	}


	//Open and create destination file for copying the content from source file
	dest_file = open("dest.txt", O_WRONLY | O_CREAT, 0664);
	
        if(dest_file == -1) {     //-1: opening src file is failed

                perror("Error opening and creating file");
                return EXIT_FAILURE;
        }

	//Copy content from source to dest file
	while (bytes_read = read(src_file, buffer, BUFF_SIZE)) {   //Read from src file intp buffer

			bytes_write = write(dest_file, buffer, bytes_read); //Write buffer content into dest file

	}

	if(bytes_read == -1) { //check if reading from src failed
	perror("Read error");
	close(src_file);
	close(dest_file);
	return EXIT_FAILURE;
	}

	close(src_file);
        close(dest_file);

	printf("File content copied successfully.\n");
	return 0;
	
}

