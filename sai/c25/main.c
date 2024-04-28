#include "main.h"


int add(int x,int y);
int mult(int x,int y);
int subt(int x,int y);
int divi(float x,float y);

void print_message(const char *message);
int main()
{
    int num1 = 50;
    int num2 = 16;

    int sum = add(num1,num2);
    int sub = subt(num1,num2);
    int mul = mult(num1,num2);
    int div = divi(num1,num2);
 

    print_message("The sum is:");
    printf("%d\n",sum);
    print_message("The sub is:");
    printf("%d\n",sub);
    print_message("The mul is:");
    printf("%d\n",mul);
    print_message("The div is:");
    printf("%d\n",div);
    return 0;
}


void print_message(const char *message)
{
	printf("%s",message);
}

