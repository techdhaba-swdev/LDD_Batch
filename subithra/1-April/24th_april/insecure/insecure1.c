//1.UNSAFE FILE ACCESS

#include <stdio.h>

int main() {
    FILE *file = fopen("important_data.txt", "r"); // Attempt to open a file
    if (file != NULL) {
        char buffer[128];
        fread(buffer, sizeof(char), 128, file); // Read data from the file
        printf("Data read from file: %s\n", buffer);
        fclose(file); // Close the file
    }
    return 0;
}



