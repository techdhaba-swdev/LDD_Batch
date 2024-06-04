#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define DEVICE_NAME "/dev/double_val"
int main()
{
int fd , value;

printf("enter the number \n");
scanf ("%d",&value);

fd = open(DEVICE_NAME , O_WRONLY);

if (fd == -1)
{
printf ("failed to open file ");
return -1 ;
}

if (write (fd ,&value , sizeof(int)) > 0)
{

printf ("value from user space is %d \n", value);
}
else 
{
printf ("value writing error\n");
}
if (read(fd , &value , sizeof(int)) >0)
{
	printf("%d doubled value from user space \n ", value);
}


close(fd);
return 0;
}
