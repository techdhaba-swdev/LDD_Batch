#include <stdio.h>
int main(){

        FILE *fp = fopen("data.txt","w");
        if(fp == NULL){
                printf("error opening file!\n");
               return 1;
        }
        char ar[300];
        char ch[200];
        fscanf(fp,"%s",ch);
        printf("%s\n",ch);
        fseek(fp, 0, SEEK_SET);
        while(fgets(ar, sizeof(ar), fp) != NULL){
                        printf("%s",ar);
                        }

       fprintf(fp,"\nhello everone");
        fclose(fp);
        printf("successfully wrote to file.\n");
        return 0;
}

