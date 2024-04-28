#include <stdio.h>
 
int main() {
    // Open the file "data.txt" for writing (w)
    FILE *fp = fopen("data.txt", "w");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }


    char arr[100];
    char ch[100];

    fseek(fp, 0, SEEK_SET);
    while(fgets(arr, sizeof(arr),fp)!=NULL)
    {
	    printf("%s",arr);
    }

 
    // Close the file
    fclose(fp);
 
    printf("Successfully wrote to the file.\n");
    return 0;
}
