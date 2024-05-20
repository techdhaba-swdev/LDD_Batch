#include <stdio.h>

int main() {
    FILE *file;
    char name[50];
    int id;
    char subject[50];

    // Open the file for reading
    file = fopen("data.txt", "r");

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

    // Close the file
    fclose(file);

    return 0;
}
