#include <stdio.h>
 
int main() {

    FILE *fp = fopen("data.txt", "w");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
 
    fprintf(fp, "This is some sample text written to the file.\n");

    fclose(fp);
 
    printf("Successfully wrote to the file.\n");
    return 0;
}
