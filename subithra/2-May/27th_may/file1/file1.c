#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFERSIZE 1024

void copy(const char *src, const char *dest) {
int srcfd, destfd;
ssize_t rd, wr;
char buf[BUFFERSIZE];

srcfd = open(src, O_RDONLY);
if(srcfd < 0) {
perror("Error opening source file");
exit(EXIT_FAILURE);
}

destfd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if(destfd < 0) {
perror("Error opening destination file");
close(srcfd);
exit(EXIT_FAILURE);
}

while((rd = read(srcfd, buf, BUFFERSIZE)) > 0) {
wr = write(destfd, buf, rd);
if(wr != rd) {
perror("Error writing to destination file");
close(srcfd);
close(destfd);
exit(EXIT_FAILURE);
}
}

if(rd < 0) {
perror("Error reading from source file");
}

if(close(srcfd) < 0 || close(destfd) < 0) {
perror("Error closing files");
}

printf("Copied successfully from '%s' to '%s'\n", src, dest);
}

int main() {
char src[256], dest[256];

printf("Enter source file path: ");
if(fgets(src, sizeof(src), stdin) == NULL) {
perror("Error reading source file path");
exit(EXIT_FAILURE);
}
src[strcspn(src, "\n")] = '\0';

printf("Enter destination file path: ");
if(fgets(dest, sizeof(dest), stdin) == NULL) {
perror("Error reading destination file path");
exit(EXIT_FAILURE);
}
dest[strcspn(dest, "\n")] = '\0';

copy(src, dest);

return 0;
}
