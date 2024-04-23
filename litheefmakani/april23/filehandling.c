#include<stdio.h>

int main(){
	//open the file "data.txt" for writing (w)
	FILE *fp = fopen("data.txt","w");

	if(fp==NULL){
		printf("Error opening files!\n");
		return 1;
	}
	//write some content to the file
	fprintf(fp,"this is same sample text written to the file.\n");
	//close the file

	fclose(fp);

	printf("Successfully wrote to te file.\n");
	return 0;
}
