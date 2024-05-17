#include<thread.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialized mutex

//write_even_lines api
void *write_even_lines(void *filename) 
{
    FILE *input_file = fopen((char *)filename, "r"); //created a input file pointer
    FILE *output_file = fopen("even_lines.txt", "w"); //created a output file pointer
    if (input_file == NULL || output_file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, sizeof(line), input_file) != NULL) //chcks the input not equal  to null
    {
        if (line_number % 2 == 0) 
	{
            pthread_mutex_lock(&mutex);
            fprintf(output_file, "%s", line);
            pthread_mutex_unlock(&mutex);
        }
        line_number++;
    }

    fclose(input_file);
    fclose(output_file);
    pthread_exit(NULL);

}
//appi of writE-odd_lines
void *write_odd_lines(void *filename) 
{
    FILE *input_file = fopen((char *)filename, "r");
    FILE *output_file = fopen("odd_lines.txt", "w");
    if (input_file == NULL || output_file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, sizeof(line), input_file) != NULL) 
    {
        if (line_number % 2 != 0) 
	{
            pthread_mutex_lock(&mutex);
            fprintf(output_file, "%s", line);
            pthread_mutex_unlock(&mutex);
        }
        line_number++;
    }
    fclose(input_file);
    fclose(output_file);
    pthread_exit(NULL);
}
void *read_file(void *filename) 
{
    FILE *file = fopen((char *)filename, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        printf("%s", line);
    }
    fclose(file);
    pthread_exit(NULL);
}
