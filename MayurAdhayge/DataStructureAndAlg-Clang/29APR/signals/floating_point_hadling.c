#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void custom_error_FP(int SIG_NUM) {
	if (SIG_NUM == SIGFPE)
	{
            printf("%d  :Floating-point exception occurred. Please change the value.\n",SIG_NUM);
             exit(EXIT_FAILURE);
	}
	else if (SIG_NUM == SIGFPE)
	{
	}
}

int main() {
    
    if (signal(SIGFPE, custom_error_FP) == SIG_ERR) {
        perror("Unable to set the SIGFPE signal handler.");
        return EXIT_FAILURE;
    }

     int sum,a=10,b=0;
    sum = a/b;

     printf("%d", sum);

    return 0;
}
