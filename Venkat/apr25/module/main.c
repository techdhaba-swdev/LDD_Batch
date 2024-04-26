#include "main.h"

int main() {
	int num1 = 20;
        int num2 = 30;

	int sum = add(num1, num2); // function call
	
	// clear message after call 
	print_message("sum is :");
	printf("%d\n", sum);

	return 0; // successful program termination 
}
