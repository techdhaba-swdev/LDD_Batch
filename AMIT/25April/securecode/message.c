#include<stdio.h>

void print_message(const char *message) {     //print_message is function with parameter const cahr *message
					      //a ponter to the constant cahr that reoresent message
					      //const indicate that content of the message cannot be modify in the fn.
    printf("%s", message);    //it will display message
}
