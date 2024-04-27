#include"main.h"

int main()
{
printf(" Addition of 2 numbers : 15 + 5 = %d\n", add(15, 5));
printf(" Subtraction of 2 numbers : 15 - 5 = %d\n", sub(15, 5));
printf(" Multipication of 2 numbers : 5 * 5 = %d\n", mul(5, 5));
printf(" Division of 2 numbers : 15 / 5 = %d\n", divide(15, 5));

printf(" Addition of 3 numbers : 15 + 5 + 5 = %d\n", add_three(15, 5, 5));
printf(" Subtraction of 3 numbers : 15 - 5 - 5 = %d\n", sub_three(15, 5, 5));
printf(" Multiplication of 3 numbers : 5 * 5 * 5 = %d\n", mul_three(5, 5, 5));

printf(" Addition of 4 numbers : 15 + 5 + 5 + 5 = %d\n", add_four(15, 5, 5, 5));
printf(" Subtraction of 4 numbers : 15 - 5 - 5 - 4 = %d\n", sub_four(15, 5, 5, 4));
printf(" Multiplication of 4 numbers : 5 * 5 * 5 * 5 = %d\n", mul_four(5, 5, 5, 5));

return 0;
}
