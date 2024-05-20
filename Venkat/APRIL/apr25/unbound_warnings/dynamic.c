#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int *ptr = malloc(sizeof(int) *10);
	if(ptr == NULL) {
		printf("memoery allocation failed . existing \n");
		return 1;
	}
	printf("allocated memory %p\n", (void *)ptr);
			return 0;
}
