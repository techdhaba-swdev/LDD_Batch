#include<stdio.h>
print_value_upto_n(int num){
    if(n<0)
    {
        return 1;
    }
    else 
    {
        printf("value is %d \n",n);
       print_value_upto_n(n-1); 
    }
    }

int main()
{
   print_value_upto_n(10);
}
