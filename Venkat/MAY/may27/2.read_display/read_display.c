#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[100];

    
    file = fopen("hello.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

  
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

  
    fclose(file);

    printf("End of file reached. File closed.\n");

    return 0;
}
