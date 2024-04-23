#include <stdio.h>
 
int main() {
    FILE *fp = fopen("data.txt", "r");
 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
char arr[100];
char a[100];
fscanf(fp,"%s",a);
printf("%s\n",a);
fseek(fp,0,SEEK_SET);
while(fgets(arr,sizeof(arr),fp) != NULL)
		{
		printf("%s",arr);
		}

    fprintf(fp, "This is some sample text written to the file.\n");
 
    printf("Successfully wrote to the file.\n");
    return 0;
}

