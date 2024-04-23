#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for exit() function

int main() {
    // Open the file "data.txt" for reading and writing (r+)
    FILE *fp = fopen("data.txt", "r+");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and print the contents of the file
    printf("Contents of the file:\n");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    // Write some content to the file
    fprintf(fp, "\nThis is additional text written to the file.");

    // Close the file
    fclose(fp);

}
