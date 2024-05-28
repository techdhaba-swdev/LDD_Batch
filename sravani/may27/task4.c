#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define FILENAME "example.txt"

int main(){
	struct stat file;
	if(stat(FILENAME,&file)==-1){
		perror("failed\n");
		exit(EXIT_FAILURE);
	}
	printf("file:%s\n",FILENAME);
	printf("inode number:%lu\n",file.st_ino);
	printf("block size:%ld bytes\n",file.st_blksize);
}

