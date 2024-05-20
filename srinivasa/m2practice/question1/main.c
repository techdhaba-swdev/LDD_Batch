// including the required  header files
#include <stdio.h>
#include <stdlib.h>
#include "gps.h"

#define LINE_BUFFER_SIZE 256

// main function 
int main() {
    const char* filepath = "data.txt";
    // opeing the file
    FILE* file = fopen(filepath, "r");

    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[LINE_BUFFER_SIZE];

    while (fgets(line, sizeof(line), file)) {
	// process every line
        processGPSLine(line); 
    }
     // closing the file
    fclose(file);
    return 0;
}
