#include <stdio.h>
 
int main() {
  struct data {
    int number;
    char name[20];
  };
 
  struct data data_to_write = {10, "Example Data"};
  struct data data_to_read;
  FILE *fp;
 
 
  fp = fopen("my_data.bin", "wb");

  if (fp == NULL) {
    perror("fopen (write)");
    return 1;
  }
 
  fwrite(&data_to_write, sizeof(data_to_write), 1, fp);
 
  if (ferror(fp)) {
    perror("fwrite");
    fclose(fp);
    return 1;
  }
 
  printf("Successfully wrote data to the file.\n");
  fclose(fp);
  fp = fopen("my_data.bin", "rb");
 
  
  if (fp == NULL) {
    perror("fopen (read)");
    return 1;
  }
 
  
  fread(&data_to_read, sizeof(data_to_read), 1, fp);
 
  if (ferror(fp)) {
    perror("fread");
    fclose(fp);
    return 1;
  }
 
  printf("Read data from the file:\n");
  printf("Number: %d\n", data_to_read.number);
  printf("Name: %s\n", data_to_read.name);
  fclose(fp);
 
  return 0;
}
