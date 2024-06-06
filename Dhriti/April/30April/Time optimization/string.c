#include <stdio.h>
#include <string.h>
#include<time.h>
int main() {

	  clock_t start = clock(); //start the clock
    char str[] = "hello";
    int length = strlen(str);

    printf("Original string: %s\n", str);

    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

     clock_t end = clock(); //stop the clock

        double time_taken = ((double)(end - start)); //cal the elapsed time'


    printf("Reversed string: %s\n", str);

    printf("Time taken: %f seconds \n",time_taken);

    return 0;
}

