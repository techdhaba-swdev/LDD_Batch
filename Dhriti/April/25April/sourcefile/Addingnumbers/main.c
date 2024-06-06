#include "main.h"

int main() {

	int num1 = 10; 
	int num2 = 20;
	int num3 = 30;
	int num4 = 40;

	int sum = add2(num1, num2);	//Function call with meaningful variable names
        int sum3 = add3(num1, num2, num3);
	int sum4 = add4(num1, num2, num3, num4);

	print_message("The sum for two numbers is: "); //Clear and concise message

	printf("%d\n",sum);

	print_message("The sum for three numbers is: "); 

        printf("%d\n",sum3);


	print_message("The sum for four numbers is: ");

        printf("%d\n",sum4);


 
	return 0; // Indicate successful program termination
}

