#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int main(){
	//intialize the mutex
	pthread_mutex_init(&mutex,NULL);
	input_file = fopen("input.txt", "r");
	if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
	}

    // Open output files for writing
        even_output_file = fopen("even_output.txt", "w");
        if (even_output_file == NULL) {
        perror("Error opening even output file");
        return 1;
        }

        odd_output_file = fopen("odd_output.txt", "w");
        if (odd_output_file == NULL) {
        perror("Error opening odd output file");
        return 1;
        }
	pthread_t write_thread1,write_thread2;//we have create two threads
        pthread_create(&write_thread1, NULL,write_even_lines,NULL);
        pthread_create(&write_thread2,NULL,write_odd_lines,NULL);
//JOIN THE THREADS
        pthread_join(write_thread1,NULL);
        pthread_join(write_thread2,NULL);
//WE HAVE TO CREATE THREADS FOR reading and printing
        pthread_t read_thread1,read_thread2;
        pthread_create(&read_thread1,NULL,read_print_even,NULL);
        pthread_create(&read_thread2,NULL,read_print_odd,NULL);
//JOIN THE THREADS FOR READING AND PRINTING
        pthread_join(read_thread1,NULL);
        pthread_join(read_thread2,NULL);

}
