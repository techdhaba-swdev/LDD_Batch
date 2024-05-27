#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *filename = "file.txt";
    char line[256];

  
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

   
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    
    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }
 return EXIT_SUCCESS;
}
