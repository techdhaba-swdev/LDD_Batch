#include<stdio.h>

int main() {
	FILE *fp = fopen("data.txt", "r");
	if(fp == NULL) {
		printf("Error opening file!\n");
		return 1;
	}
	char arr[400];
	char ch[400];

	fscanf(fp, "%s", ch);
	printf("%s\n",ch);
	while(fgets(arr, sizeof(arr), fp) != NULL){
		printf("%s", arr);
	}
	fclose(fp);
	printf("successfully read from the file.\n");
	return 0;
} 
