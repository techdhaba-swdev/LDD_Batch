#include <stdio.h>
int fibonacci(int n) {
	if (n <= 1)


		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
void printFibonacciSeries(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", fibonacci(i));
	}
}
int main() {
	int n = 5;
	printf("Fibonacci series up to %d terms:\n", n);
	printFibonacciSeries(n);
	printf("\n");
	return 0;
}
