#include<stdio.h>
#include<sys/stat.h>
#define MAX_LEN 100
int main(){
	struct stat buff;
	FILE *source_file=fopen("source.txt","r");
	if(source_file==NULL){
		perror("open");
		return 1;
	}
	char ch[MAX_LEN];
	while((fgets(ch,MAX_LEN,source_file))!=NULL){
		printf("%s",ch);
	}
	if(lstat("source.txt",&buff)==-1){
		perror("lstat");
		return 1;
	}
	printf("Inode number of file is %lu\n",buff.st_ino);
	printf("Block size is %lu\n",buff.st_blksize);
	printf("User id is %lu\n",buff.st_uid);
	printf("Total size in bytes is %lu\n",buff.st_size);
	printf("File type: ");

        switch (buff.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

	close(source_file);
	return 0;
}
	
