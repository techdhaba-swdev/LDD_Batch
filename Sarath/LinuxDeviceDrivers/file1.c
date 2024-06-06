#include <stdio.h>

int main() {
  char data[] = "This is some data to write to the file.\n";
  char source[]="my_file.txt";
  char dest[]="my_file2.txt";
  // Open the file "my_file.txt" in read-write mode with create flag
  FILE *fd1 = fopen("my_file.txt", "rw");
  FILE *fd2 = fopen("my_file2.txt","rw");
  // Check if opening the file was successful
  if (fd1 == NULL || fd2 == NULL) {
    perror("open");
    return 1;
  }
  while(fgetc(fd1)!=EOF){
	   if(fputc(fd2,fd1)==EOF){
		   printf("Error\n");
		   close(fd1);
		   close(fd2);
	   }
   }
  // Close the file
  close(fd1);
  close(fd2);
 
  return 0;
}
