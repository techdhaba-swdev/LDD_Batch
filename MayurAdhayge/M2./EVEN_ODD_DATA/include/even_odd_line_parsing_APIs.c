#include "parsing_APIs.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialized mutex

// Function to write even lines to a file
void *writeEvenLines(void *filename) 
{
    char *inputFilename = (char *)filename; // Input file name
    FILE *inputFile = fopen(inputFilename, "r"); // Input file pointer
    FILE *outputFile = fopen("even_lines.txt", "w"); // Output file pointer for even lines
    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH]; // Buffer to store each line
    int lineNumber = 1; // Line number counter
    while (fgets(line, sizeof(line), inputFile) != NULL) // Read each line from the input file
    {
        if (lineNumber % 2 == 0) // Check if the line number is even
        {
            pthread_mutex_lock(&mutex); // Lock the mutex before writing to the file
            fprintf(outputFile, "%s", line); // Write the line to the output file
            pthread_mutex_unlock(&mutex); // Unlock the mutex after writing
        }
        lineNumber++; // Increment line number
    }

    fclose(inputFile); // Close input file
    fclose(outputFile); // Close output file
    pthread_exit(NULL); // Exit the thread
}

// Function to write odd lines to a file
void *writeOddLines(void *filename) 
{
    char *inputFilename = (char *)filename; // Input file name
    FILE *inputFile = fopen(inputFilename, "r"); // Input file pointer
    FILE *outputFile = fopen("odd_lines.txt", "w"); // Output file pointer for odd lines
    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH]; // Buffer to store each line
    int lineNumber = 1; // Line number counter
    while (fgets(line, sizeof(line), inputFile) != NULL) // Read each line from the input file
    {
        if (lineNumber % 2 != 0) // Check if the line number is odd
        {
            pthread_mutex_lock(&mutex); // Lock the mutex before writing to the file
            fprintf(outputFile, "%s", line); // Write the line to the output file
            pthread_mutex_unlock(&mutex); // Unlock the mutex after writing
        }
        lineNumber++; // Increment line number
    }

    fclose(inputFile); // Close input file
    fclose(outputFile); // Close output file
    pthread_exit(NULL); // Exit the thread
}

// Function to read and print lines from a file
void *readFile(void *filename) 
{
    char *inputFilename = (char *)filename; // Input file name
    FILE *file = fopen(inputFilename, "r"); // File pointer
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH]; // Buffer to store each line
    while (fgets(line, sizeof(line), file) != NULL) // Read each line from the file
    {
        printf("%s", line); // Print the line
    }

    fclose(file); // Close the file
    pthread_exit(NULL); // Exit the thread
}
