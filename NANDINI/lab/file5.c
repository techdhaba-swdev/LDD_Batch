#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(const char *path) {
    struct stat sb;

    if (lstat(path, &sb) == -1) 
    {
        perror("lstat");
        return;
    }

  
    if (S_ISREG(sb.st_mode)) {
        printf("%s is a regular file.\n", path);
    } else if (S_ISDIR(sb.st_mode)) {
        printf("%s is a directory.\n", path);
    } else if (S_ISLNK(sb.st_mode)) {
        printf("%s is a symbolic link.\n", path);
    } else if (S_ISCHR(sb.st_mode)) {
        printf("%s is a character device.\n", path);
    } else if (S_ISBLK(sb.st_mode)) {
        printf("%s is a block device.\n", path);
    } else if (S_ISFIFO(sb.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", path);
    } else if (S_ISSOCK(sb.st_mode)) {
        printf("%s is a socket.\n", path);
    } else {
        printf("%s is of unknown type.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    print_file_type(argv[1]);

    return 0;
}
