#include <stdio.h>
 
int main() {
    // Open the file "data.txt" for writing (w)
    FILE *fp = fopen("data.txt", "w");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
 
    // Write some content to the file
    fprintf(fp, "This is some sample text written to the file.\n");
    fprintf(fp,"hello world!\n");
 
    // Close the file
    fclose(fp);
 
    printf("Successfully wrote to the file.\n");
    return 0;
}
