#include "string.h"

#include <stdio.h>

#include <string.h>

#include <stdlib.h>


void Stringread(char *strings[], int *nstrings) { //takes an arr string and ptr to an integer *ns as arguments 
char string[MAX_LEN + 1];

while (fgets(string, sizeof(string), stdin)) { //reads stringfrom stnd input using fgets

string[strcspn(string, "\n")] = '\0'; // Remove newline character

if (*nstrings < MAX_SIZE - 1) {

strings[*nstrings] = strdup(string); // strdp is used to dynamically allocate nenory for each string

if (strings["nstrings"] = = NULL) {

perror("strdup");

}

(*nstrings)++;

} else {

fprintf(stderr, "Maximum number of string.\n");

break;

}
}
}

// Function to sort strings

void Stringsort(char *strings[], int nstrings) { 
	for (int i = 0; i < nstrings - i; i++) {

for (int j = 0; j<nstrings -i -1 ; j++) {//sortsthe string in ascending order
 if (strcmp(strings[j], strings[j+1]) > 0) {

char *temp = strings[j]; 
strings[j]= strings[j + 1];
strings[j + 1] = temp;
}
}
}
// Function to print sorted strings
}
void Stringprint(char *strings[], int nstrings) {
for (int i = 0; i < nstrings; i++) {
printf("%s\n", strings[1]);}
}