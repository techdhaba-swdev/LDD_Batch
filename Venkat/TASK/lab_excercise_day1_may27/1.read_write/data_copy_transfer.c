#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r");
    if (source == NULL) {
        printf("Cannot open source file.\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen("destination.txt", "w");
    if (destination == NULL) {
        fclose(source);
        printf("Cannot open destination file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n"); 
    // here is successfully opened file read from soruce file to destination file and close from below i will show what content written
    destination = fopen("destination.txt", "r");
    if (destination == NULL) {
        printf("Cannot open destination file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Content copied to destination:\n");
    while ((ch = fgetc(destination)) != EOF) {
        putchar(ch); // printf("%c ",ch); or  fprintf(stdout,"%c",ch);
    }

    fclose(destination);



    return 0;
}
