#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s  <input.txt>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024]; // Adjust buffer size as needed

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Display each line
    }

    if (feof(file)) {
        printf("\nEnd of file reached.\n");
    } else {
        perror("Error reading file");
    }

    fclose(file);
    return 0;
}

