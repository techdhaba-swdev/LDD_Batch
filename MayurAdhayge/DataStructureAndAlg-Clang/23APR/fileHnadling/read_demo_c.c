#include <stdio.h>
 
int main() {
    // Open the file "data.txt" for writing (w)
    FILE *fp = fopen("data.txt", "r");
    int buffer;
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
 
    // Write some content to the file
    buffer=getc(fp);
    int c=0;
  
     while(buffer!=EOF)
     {
     putchar(buffer);
     c++;
     buffer=getc(fp);
     } 
     printf("%d",c);
    // Close the file
    fclose(fp);
 
    return 0;
}
