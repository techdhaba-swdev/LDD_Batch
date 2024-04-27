#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

int main() {
    // Open the file "data.txt" for reading and writing
    FILE* fp = openFileReadWrite("data.txt");

    // Read and print the contents of the file
    readAndPrintFile(fp);

    // Write some content to the file
    writeAdditionalContent(fp, "This is additional text written to the file.");

    // Close the file
    fclose(fp);

    return 0;
}
