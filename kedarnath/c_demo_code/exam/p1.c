#include <stdio.h>
#include <string.h>

int main() {

    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file %s\n", "data.txt");
        return;
    }

    char line[100]; // Assuming each line in the file is at most 100 characters long
    while (fgets(line, sizeof(line), file)) {

        //printf("Student data: %s", line);
	char *token;

    // Split the data using strtok
    token = strtok(line, ",");
    while (token != NULL) {
        printf(" %s\n", token);
        token = strtok(NULL, ",");
    }

    }

    fclose(file);

    return 0;
}

