#include <stdio.h>
#define MAX_LENGTH 100

int main() {
	FILE *file;
	char name[MAX_LENGTH];
	int id;
	char subject[MAX_LENGTH];
	file = fopen("studentdata.txt", "r");
	if (file == NULL) { 
		printf("Error opening the file.\n"); 
		return 1;
	}

	while (fscanf(file, "%s %d %s", name, &id, subject) != EOF) 
	{
		printf("Name: %s\n", name);
		printf("ID: %d\n", id);
		printf("Subject: %s\n", subject);
	}

	fclose(file);

return 0;

}

