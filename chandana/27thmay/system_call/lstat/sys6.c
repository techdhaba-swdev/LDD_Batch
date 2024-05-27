#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void display_file_type(const char *file){
	struct stat f_stat;

	//get file statistics using lstat
	if(lstat(file,&f_stat)==-1){
		perror("lstat");
		exit(EXIT_FAILURE);
	}
//find the file type
printf("file :%s\n",file);
printf("file_type: ");
if(S_ISREG(f_stat.st_mode)){
	printf("regular file\n");
}
else if (S_ISDIR(f_stat.st_mode)){
	printf("directory\n");
}
else
{
	printf("unknown\n");
}
}
int main(int argc,char *argv[]){
	if(argc!=2){
		fprintf(stderr,"usage :%s <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	display_file_type(argv[1]);
	return 0;
}
