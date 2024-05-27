#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fd = open("sample.txt", O_RDONLY);
    
  
    char *buffer=(char *) malloc(BUFFER_SIZE);
    char *bufferfree=buffer;
    ssize_t bytes_read;
    char* newline_pos;
    char tmp[100];
    bytes_read = read(fd, buffer,BUFFER_SIZE);
    ssize_t count=0;
    while ( count!= bytes_read) {
        char *ptr = buffer;
        newline_pos = strchr(ptr, '\n');
        *newline_pos = '\0'; 
        strcpy(tmp,buffer);
        printf("Line: %s\n", tmp);
        buffer = newline_pos + 1; 
        count=count+strlen(tmp)+1;
        }
    close(fd);
    free(bufferfree);
    return 0;
}
