#include"thread.h"//includes custom headerfile for additional thread definitions
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialized mutex

//function to write_even_lines api
void *write_even_lines(void *filename) 
{
    FILE *input_file = fopen((char *)filename, "r"); //open input file in read mode
    FILE *output_file = fopen("even_lines.txt", "w"); //open output file to write even number of lines
    if (input_file == NULL || output_file == NULL) // checks if files opened successfully
    {
        perror("Error opening file");//print error message if condition fails
        exit(EXIT_FAILURE);//exits the program unsuccessfully
    }

    char line[MAX_LINE_LENGTH];//buffer to store each line
    int line_number = 1;// line number counter
    while (fgets(line, sizeof(line), input_file) != NULL) //chcks the input not equal  to null
    {
        if (line_number % 2 == 0) //checks if line number is even
	{
            pthread_mutex_lock(&mutex);//lock mutex
            fprintf(output_file, "%s", line);//write line to output file
            pthread_mutex_unlock(&mutex);//unlock mutex
        }
        line_number++;//increment line number
    }

    fclose(input_file);//close input file
    fclose(output_file);//close output file
    pthread_exit(NULL);//exit thread

}
//function  to write-odd_lines to a file
void *write_odd_lines(void *filename) 
{
    FILE *input_file = fopen((char *)filename, "r");//open input file in read mode
    FILE *output_file = fopen("odd_lines.txt", "w");//open output file in write mode
    if (input_file == NULL || output_file == NULL) //checks if files opened succesfully
    {
        perror("Error opening file");//print error message if condition fails
        exit(EXIT_FAILURE);//exits program unsuccessfully
    }

    char line[MAX_LINE_LENGTH];//buffer to store each line
    int line_number = 1;//line number counter
    while (fgets(line, sizeof(line), input_file) != NULL) //read each line from input file
    {
        if (line_number % 2 != 0) //check if line is odd or not
	{
            pthread_mutex_lock(&mutex);//lock mutex
            fprintf(output_file, "%s", line);//write line to output file
            pthread_mutex_unlock(&mutex);//unlock mutex
        }
        line_number++;//linenuber increment
    }
    fclose(input_file);//close inputfile
    fclose(output_file);//close outputfile
    pthread_exit(NULL);//exit thread
}
void *read_file(void *filename) //function t readfile
{
    FILE *file = fopen((char *)filename, "r");//open file in read mode
    if (file == NULL) //checking file is null or not
    {
        perror("Error opening file");//print error message in opening file
        exit(EXIT_FAILURE);//exit program on failure
    }
    char line[MAX_LINE_LENGTH];//buffer to store each line
    while (fgets(line, sizeof(line), file) != NULL) //read each line from file
    {
        printf("%s", line);//print line to standard output
    }
    fclose(file);//close file
    pthread_exit(NULL);//exit thread
}
