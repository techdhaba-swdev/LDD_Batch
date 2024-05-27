#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	struct stat file;
	char *filename = "question2.c";
	stat(filename, &file);
	printf(" inode number : %ld\n", file.st_ino);
	printf("block size of file : %ld\n",file.st_blksize);
	if (S_ISREG(file.st_mode))
		printf(" file is a regular file");
	else if (S_ISDIR(file.st_mode))
		printf(" file is a directory");
	else if (S_ISCHR(file.st_mode))
		printf(" file is a character device");
	else 
		printf(" file is unknown ");


	return 0;
}

