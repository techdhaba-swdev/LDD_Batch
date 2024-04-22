#include <stdio.h>
int  add_dynamic(int x , int y)
{

int sum = 0;
sum = x + y;
printf("sum of two numbers : %d\n",sum);
}
int sub_dynamic(int x , int y)
{
int sub =0;
sub = x -  y;
printf("sub of two numbers:%d\n",sub);
}
int mul_dynamic(int x , int y)
{
int mul =0;
mul = x*y;
printf("mul of two numbers:%d\n",mul);

}
int div_dynamic(int x , int y)
{
int div = 0;
div = x/y;
if (y == 0 )
printf("arithmatic exception");
else
printf("division of two numbers :%d\n",div);
}
