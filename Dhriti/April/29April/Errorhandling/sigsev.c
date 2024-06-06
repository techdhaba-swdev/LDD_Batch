#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigsegv_handler(int signum) {
	printf("Segmentation fault has been occured.. \n");
	exit(signum);
}

int main() {
	signal(SIGSEGV, sigsegv_handler);

	int arr[4] = {1,2,3,4};

	printf("%d\n", arr[8]);

	return 0;
}
