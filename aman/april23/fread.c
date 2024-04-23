#include<stdio.h>
int main() {
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL){
		printf("error opening file.\n");
		return 1;
	}
	char buffer[250];
	while (fgets(buffer, sizeof(buffer), fp)) {
		printf("%s", buffer);
	}
	fclose(fp);
	return 0;
}
