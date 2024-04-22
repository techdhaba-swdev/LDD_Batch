#include "headers/functionDeclaration.h"

int main(){
char *tempPtr;
int firstNum=-1,secondNum=-1,opration=-1;
isvalid=0;
char expression[10];
printf("enter your opration :-");
scanf("%s",&expression);
while(*ptr!='\0')
{

if(isdigit(*ptr) && opration == -1)
{
firstNum++;
ptr++;
}

else if(!isdigit(*ptr) && opration == -1 )
{
opration=firstNum+1;
secondNum=opration;
ptr++;
}

else{
printf("enter the right expresion using symbol +,-,*,/");
isvalid=0;
}


}

