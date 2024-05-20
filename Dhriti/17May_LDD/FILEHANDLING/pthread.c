#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_SIZE 1000
#define MAX_LINE_SIZE 1000

char inputFileText[] = "input.txt";
char outputFileOdd[] = "output_odd.txt";
char outputFileEven[] = "output_even.txt";

char lines[MAX_SIZE][MAX_LINE_SIZE]; // Stores lines from the input file
int count = 0;

int main() {
	FILE *inputfile = fopen(inputFileText, "r"); // Open input file
	
	pthread_t threads[2]; // Declaring variables for thread
        int threadIds[2] = {1,2};

	while(fgets(lines[count],MAX_LINE_SIZE,inputfile)) { // Reading lines from the input files
		count++;
	}

	fclose(inputfile);


	FILE *outputfiles[2]; // Stores output lines pointer
	outputfiles[0] = fopen(outputFileOdd, "w");
	outputfiles[1] = fopen(outputFileEven, "w");

	for(int i=0;i<2;i++) {  // Iterate through the lines and write them to output files
		for(int j=i; j<count; j+=2) {
			fprintf(outputfiles[i], "%s", lines[j]);
		}
		fclose(outputfiles[i]); // Close the output files after writing
	}
	return 0;
}
