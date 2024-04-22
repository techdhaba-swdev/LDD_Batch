//----------------------------------------------Author :- Mayur Adhayge------------------------------------------------------------------//

//----------------------------header section  -------------------------------------//
#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
//---------------------------end  header section-----------------------------------//

//--------------------------start of function declaration--------------------------//
void print_arg_multi(int noOf_arg,...);
//-------------------------end of function declaration-----------------------------//


//------------------------------------------------------function defination start--------------------------------------//


//function print_arg_multi take the variable of agrgument and print them 
void print_arg_multi(int noOf_arg,...)
{

 va_list argList;
 char* str= (char*) malloc(sizeof(char));
 str[0]='\0';
 va_start(argList,noOf_arg);
 printf("\n");
 for(int i=0;i<noOf_arg;i++)
 {
     //printf("%d ",va_arg(argList,int));
     

     //this if-else block given because i pass the alternate int char value to function
     if (i%2==0){
         printf("%d ",va_arg(argList,int));
     }
     else
     {
        //  char tmp[2];
        //  tmp[0]= va_arg(argList,int);
        //  tmp[1]='\0';
        // strcat(str,tmp);
        str=(char*) realloc(str,strlen(str)+1);
        int n=strlen(str);
        str[n]=va_arg(argList,int);
        str[n+1]='\0';
        
     }
//  printf("%d ",va_arg(argList,int));
 }
 printf("\n%s\n",str);
    
}
//--------------------end of function print_arg_multi------------------------//


//------------------------------------------------end of function definations-------------------------------//





int main()
{
    print_arg_multi(10,1,'m',2,'a',3,'y',4,'u',5,'r');
    print_arg_multi(5,1,'m',2,'a',3);
    print_arg_multi(2,1,'m');

    return 0;
}
