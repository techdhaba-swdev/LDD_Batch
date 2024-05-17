#include <stdio.h>

#define MAX_LENGTH 100

int main() {

FILE *file;

char name[MAX_LENGTH];

int id;

char subject[MAX_LENGTH];

// Open the file for reading

 file = fopen("students.txt", "r");



if (file == NULL) {
       	printf("Error opening the file.\n");
       	return 1;

}

// Read data from the file and print it

while (fscanf(file, "%s %d %s", name, &id, subject) != EOF) {

printf("Name: %s\n", name);

printf("ID: %d\n", id);

printf("Subject: %s\n", subject);

}

// Close the file fclose(file);

return 0;

}
