#include <stdio.h>

int main() {

FILE *file = fopen("data.txt", "г");

if (file != NULL) {

fseek(file, 6, SEEK_SET);

printf("Current position: %ld\n", ftell(file));

rewind(file);

printf("Current position: %ld\n", ftell (file)); fclose(file);

} else {

printf("Failed to open file.\n");

}

return 0;

}
