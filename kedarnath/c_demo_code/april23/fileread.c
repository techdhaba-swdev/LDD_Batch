#include <stdio.h>
 
int main() {
    // Open the file "data.txt" for reading (r)
    FILE *fp = fopen("data.txt", "r");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
 
    
    char arr[200];
    char ch[200];
    
    fscanf(fp,"%s",ch);
    printf("%s\n",ch);

    
    fseek(fp, 0, SEEK_SET);

    
    while(fgets(arr, sizeof(arr), fp) != NULL){
        printf("%s", arr);
    }
    
    
 
    // Close the file
    fclose(fp);
    printf("Successfully read from the file.\n");
    return 0;
}




