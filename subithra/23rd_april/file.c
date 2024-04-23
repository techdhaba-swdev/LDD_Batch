#include<stdio.h>
int main(){
	FILE*fp = fopen("data.txt","r+");

	if(fp==NULL){
		printf("error in opening file\n");
		return 1;
	}
printf("contents in the file\n");
int c;
while((c=fgetc(fp))!=EOF){
putchar(c);
	}
	fprintf(fp,"this is extra text written to the file.\n");
	
	
	fclose (fp);
          
	
	return 0;
}
