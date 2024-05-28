#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *file;
	file = fopen("file.txt", "r");
	if (file == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		printf("%s", buffer);
	}
	if (fclose(file) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}

	return EXIT_FAILURE;
}
