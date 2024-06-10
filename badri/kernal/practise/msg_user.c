#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/msg"
#define LEN 1000

int main()
{

int fd ;
char msg[LEN];
int bytes_read , bytes_write;

printf("enter the string \n");
scanf ("%s" , msg);
fd = open(DEVICE_NAME , O_RDWR);

if (fd < 0)
{
perror("error in opening file \n");
return -1;
}

 bytes_write = write(fd , &msg , sizeof(msg));
bytes_read = read(fd , &msg , sizeof(msg));

if (bytes_read && bytes_write < 0)
{
perror ("failed to write and read bytes \n");
return -1;
}

printf("bytes read bytes_write %d %d \n ", bytes_read , bytes_write);

printf("message is %s \n" , msg);

close(fd);

return 0;
}
