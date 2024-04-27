#include<stdio.h> //standard input and output library
#include "example.h" //implementing user own header file
                                         
int main() {
        
        //decalring variables with respective data types
        
        int num1=10;
        int num2=20;
        
        int sum=add(num1,num2); //add function is calling 
        int subst=sub(num1,num2); //sub function is calling
        int multi=mul(num1,num2); //mul function is calling
        float divi=div(num1,num2); //div function is calling
                                 
        //printing the sum sub multi and divi values by using printf
        
        printf("sum of %d+%d:%d\n", num1, num2, sum);
        printf("sub of %d-%d:%d\n",num1, num2, subst);
        printf("multiply of %d*%d:%d\n", num1, num2, multi);
        printf("division od %d/%d:%.2f\n", num2, num1, divi);
        
      
        return 0; //indicate successfull program termination
}                 
  

