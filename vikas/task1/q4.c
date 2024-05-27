#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	struct stat file;
	char *filename="exmp.c";
	stat(filename,&file);
	printf("inode number:%ld\n",file.st_ino);
	printf("block size of file:%ld\n",file.st_blksize);
	return 0;
}
