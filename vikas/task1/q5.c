#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
        struct stat file;
        char *filename="exmp.c";
        stat(filename,&file);
        printf("inode number:%ld\n",file.st_ino);
        printf("block size of file:%ld\n",file.st_blksize);
	if(S_ISREG(file.st_mode))
		printf("file is a regular file\n");
	else if(S_ISDIR(file.st_mode))
		printf("It is a directory\n");
	else if(S_ISCHR(file.st_mode))
		printf("file is a character device\n");
	else
		printf("file is unknown\n");
        return 0;
}

