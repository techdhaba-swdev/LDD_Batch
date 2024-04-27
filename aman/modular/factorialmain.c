#include <stdio.h>//include standard input ouput library like printf scanf
#include "factorial.h"//it  include header file and allow to use declaration and function defined in header file
int main(){//define main function which is entry point of this code and int is an integer and brackets tell that it has not parametres
	int num;//it declares the integer variable called num used to strore input number provided by user
	printf("Enter a non negative integer: ");// this line display message to user to input a non negative integer
	if(scanf("%d", &num) != 1 || num < 0){//this line reads interger input value by user usingscanf function and store input value in variable num and if it returns other than 1 or num is negative then it shows invalid input.
		printf("Invalid input. Please enter a non-negative integer.\n");// this lineis executed if input number provided by user is invalid
		return 1;//indiacte some error in code
	}
	printf("Factorial of %d is  %d\n", num, factorial(num));//it calculates the factorial of input number by user using factorial function decalred in header file.and teh prints the input number and factorial of input number
	return 0;//indicates successful compilation 
}

//secure code - it check the input number is non negative
