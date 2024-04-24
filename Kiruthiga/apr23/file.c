#include <stdio.h>
 
int main() {


    FILE *fp = fopen("data.txt", "r");
 
    if (fp == NULL) {

        printf("Error opening file!\n");

        return 1;

    }
 
    int read;
    printf("content of file:\n");
    while((read = fgetc(fp)) !=EOF)
    {
    	putchar(read);
    }
    fprintf(fp, "Good Afternoon\n");
    fclose(fp);

    return 0;

}


