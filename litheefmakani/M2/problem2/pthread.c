#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
FILE *input_file, *even_output_file, *odd_output_file;

void *process_numbers(void *arg) {//function for thread
    int *number = (int *)arg;
    FILE *output_file;

    if (*number % 2 == 0) {//checking the number is even or odd 
        output_file = even_output_file;
    } else {
        output_file = odd_output_file;
    }

    pthread_mutex_lock(&mutex);
    fprintf(output_file, "%d\n", *number);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);//exit the thread
}

int main() {
    pthread_t threads[10]; // Assuming there are 10 numbers to process

    pthread_mutex_init(&mutex, NULL);

    input_file = fopen("input.txt", "r");//open the input file for reading purpose
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    even_output_file = fopen("even_output.txt", "w");//open the even output file for writing purpose
    if (even_output_file == NULL) {
        perror("Error opening even output file");
        return 1;
    }

    odd_output_file = fopen("odd_output.txt", "w");//open the odd output file for writing purpose
    if (odd_output_file == NULL) {
        perror("Error opening odd output file");
        return 1;
    }

    int numbers[10]; // Assuming there are 10 numbers in the input file

    // Read numbers from the input file
    for (int i = 0; i < 10; i++) {
        if (fscanf(input_file, "%d", &numbers[i]) != 1) {
            perror("Error reading input file");
            return 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, process_numbers, &numbers[i]);
    }

    // Join threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    // Close the files
    pthread_mutex_destroy(&mutex);
    fclose(input_file);
    fclose(even_output_file);
    fclose(odd_output_file);

    return 0;
}
