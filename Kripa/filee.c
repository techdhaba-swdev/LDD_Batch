#include <stdio.h>

 

int main() {
 
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    char myString[100];
    fgets(myString, 100,fp);
    printf("%s", myString);
 

    // Close the file
    fclose(fp);

}
