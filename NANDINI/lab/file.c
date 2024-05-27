#include <stdio.h>
#include <stdlib.h>

#define SOURCE_FILE "source.txt"
#define DEST_FILE "destination.txt"
#define BUFFER_SIZE 1024

int main() {
    FILE *src_fp;            //pointer to source file
    FILE *dest_fp;           //pointer to destination file
    size_t bytes_read, bytes_written;   //to store no of bytes
    char buffer[BUFFER_SIZE];          //buffer size to store data

    
    //open souce file to read

    src_fp = fopen(SOURCE_FILE, "r");
    if (src_fp == NULL)     //to check file was opened or not
    {
        perror("Failed to open source file for reading");       //error msg
        exit(EXIT_FAILURE);        //exit the program
    }

     //open destination file to write
   
    dest_fp = fopen(DEST_FILE, "w");
    if (dest_fp == NULL)    //to check file opened or not
    {         
        perror("Failed to open destination file for writing");   //error msg
        fclose(src_fp); //close src file if destiny file fails
        exit(EXIT_FAILURE);
    }


   //copies content from source file to destination file
   
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_fp)) > 0) //reads data frm src file to buffer
    {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_fp);    //writes data frm buffer to destiny file
        if (bytes_written != bytes_read)       //to check all written or not
	{

            perror("Failed to write to destination file");  //prints error msg
            fclose(src_fp);  
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    
    if (ferror(src_fp))    //to check there was a error of reading src file
    {
        perror("Failed to read from source file");   //prints error msg
    }

    
    fclose(src_fp);   //close src file
    fclose(dest_fp);  //close destiny file

    printf("source file copied successfully \n");  //prints successfull msg

    return 0;
}
