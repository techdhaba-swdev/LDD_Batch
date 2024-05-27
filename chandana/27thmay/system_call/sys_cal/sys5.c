#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void display_info(const char *file){
	struct stat f_stat;

	//get file statistics using lstat
	if(lstat(file,&f_stat)==-1){
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	//display inode num and block size
	printf("file: %s\n",file);
	printf("Inode number : %lu\n",f_stat.st_ino);
	printf("block size:%lu bytes\n",f_stat.st_blksize);
}

int main(int argc,char *argv[]){
	if(argc!=2){
		fprintf(stderr,"usage:%s <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	display_info(argv[1]);
	return 0;
}
