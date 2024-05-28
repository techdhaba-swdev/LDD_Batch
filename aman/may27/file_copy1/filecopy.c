#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024 //1KB
int main(int argc, char *argv[]) {
	int source_fd, dest_fd;
	ssize_t n_read, n_written;
	char buffer[BUFFER_SIZE];
	if(argc != 3) {
		fprintf(stderr, "Usage: <source.txt> <destination.txt>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	source_fd = open(argv[1], O_RDONLY);
	if(source_fd == -1) {
		perror("Error opening source file");
		exit(EXIT_FAILURE);
	}
	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(dest_fd == -1) {
		perror("Error opening/creating destination file");
		close(source_fd);
		exit(EXIT_FAILURE);
	}
	while ((n_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
		n_written = write(dest_fd, buffer, n_read);
		if (n_written == -1){
			perror("Error writing t destination file");
			close(source_fd);
			close(dest_fd);
			exit(EXIT_FAILURE);
		}
	}
	if (n_read == -1) {
		perror("Error reading from source file");
	}
	close(source_fd);
	close(dest_fd);
	return 0;
}

