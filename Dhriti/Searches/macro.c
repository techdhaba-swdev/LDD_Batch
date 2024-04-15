#include<stdio.h>
<<<<<<< HEAD:Dhriti/Searches/macro.c
#include<string.h>
#define concat(x, y) x##y

int main()
{
	char str1[] = "Dhriti";
	char str2[] = "Ojha";

	char string[] =  concat(str1, str2);

	printf("The printed string is: %s\n", string);

	return 0;
}
=======
#define square(x) ((x) *(x))
int main(){
	int num1 = 5;
	int num2 = 10;
	printf("square of %d: %d\n", num1, square(num1));
	printf("square of %d: %d\n", num2, square(num2));
	return 0;
}

>>>>>>> 07a27fd (hi):aman/macro.c
