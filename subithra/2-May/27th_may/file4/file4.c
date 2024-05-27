#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
int main() {
char file_path[256]; 
struct stat file_stat;

printf("Enter the file path: ");
if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
perror("Error reading file path");
return 1;
}
file_path[strcspn(file_path, "\n")] = '\0';

if (stat(file_path, &file_stat) == -1) {
perror("Error getting file information");
return 1;
}

printf("File: %s\n", file_path);
printf("Inode number: %lu\n", file_stat.st_ino);
printf("Block size: %ld bytes\n", file_stat.st_blksize);

return 0;
}
