#include <stdio.h>

int main() 
{
    char input_data[100]; 
    printf(" enter some text: ");

    
    if (fgets(input_data, sizeof(input_data), stdin) != NULL) 
    {
      
        printf("output: %s", input_data);
    } 
    else
    {

        printf("Error reading input.\n");
    }

    return 0;
}

