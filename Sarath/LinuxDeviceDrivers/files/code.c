#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFF_SIZE 4096

int main(){
	char buffer[BUFF_SIZE];
	ssize_t bytes_read;
	int source_fd=open("my_file.txt", O_RDWR | O_CREAT ,0666);
	if(source_fd==-1){
		perror("open");
		return 1;
	}
	int dest_fd=open("my_file2.txt",O_WRONLY | O_CREAT ,0666);
	if(dest_fd==-1){
		perror("dest open");
		close(source_fd);
		return 1;
	}
	while((bytes_read=read(source_fd,buffer,BUFF_SIZE))>0){
		write(dest_fd,buffer,bytes_read);
	}
	if(bytes_read==-1){
		perror("read");
		close(source_fd);
		close(dest_fd);
		return 1;
	}
	close(source_fd);
        close(dest_fd);
	return 0;
}
