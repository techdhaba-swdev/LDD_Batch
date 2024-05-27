#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileInfo;
    const char *filePath = "/home/rps/Desktop/Venkatasai/may27/3.stdin_out"; 

    //  getting the file information
    if (stat(filePath, &fileInfo) != 0) {
        perror("Error getting file information");
        return 1;
    }
    printf("The file '%s' is a ", filePath);
    switch (fileInfo.st_mode & S_IFMT) {
        case S_IFBLK:
	       	printf("block device.\n");
	       	break;
        case S_IFCHR:
	      	printf("character device.\n");
	       	break;
        case S_IFDIR:
	      	printf("directory.\n");
	       	break;
        case S_IFIFO:
	      	printf("FIFO/pipe.\n");
	       	break;
        case S_IFLNK:
	      	printf("symlink.\n");
	       	break;
        case S_IFREG:
	      	printf("regular file.\n");
	       	break;
        case S_IFSOCK:
	       	printf("socket.\n");
	       	break;
        default:
	 	printf("unknown.\n");
    }

    return 0;
}
