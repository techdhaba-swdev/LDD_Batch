#include <stdio.h>

int main() {
    char type[100]; 

    printf("Enter some text: ");

    if (fgets(type, sizeof(type), stdin)) {
   
        printf("You entered: %s", type);  // fputc(ch,type)
    }

    return 0;
}


