#include<stdio.h>


int main(){
	FILE *fp = fopen("data.txt","r");//open the data.txt file for reading(r)
	if(fp==NULL){
		printf("Error opening file!\n");
		return 1;
	}
	char buffer[100];
	printf("contents of data.txt:\n");//read and print the contents of the file 

	while(fgets(buffer,100,fp)!=NULL){
		printf("%s",buffer);
	}
	fclose(fp);//close the file
	return 0;
}
