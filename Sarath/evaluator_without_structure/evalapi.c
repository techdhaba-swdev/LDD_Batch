#include"eval.h"
char stack[MAX] ; //operators stack
int stack2[MAX];
char infix[MAX] ; //infix array used to store expression entered by user
char postfix[MAX]; //postfix array used to store whole postfix expression after convertion
int top=-1; //holds index of stack currently it is empty

void intopost()
{
    int i,j=0;
    char symbol;
    char next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(symbol=='(')
        {
            push(symbol);
        }
        else if(symbol== '+' || symbol== '-' || symbol=='*' || symbol=='/')
        {
            while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
            {
                postfix[j++]=pop();
            }
            push(symbol);
        }
        else if(symbol==')')
        {
            while((next=pop())!='(')
            {
                postfix[j++]=next;
            }
        }
        else
        {
            postfix[j++]=symbol;
        }
    }
    while(top!=-1 && stack[top]!='(')
    {
        postfix[j++]=stack[top--];
    }
   
}
void push(int val)
{
    if(top==MAX)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top]=val;
}
void push1(int val)
{
    if(top==MAX)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack2[top]=val;
}
int pop()
{
    int val;
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    val=stack[top];
    top=top-1;
    return val;
}
int pop1()
{
   
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    int val=stack2[top];
    top=top-1;
    return val;
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void print()
{
    int i=0;
    printf("The equivalent postfix is ");
    while(postfix[i])
    {
        printf("%c",postfix[i++]);
    }
    printf("\n");
}
int precedence(int symbol)
{
    if(symbol=='/' || symbol=='*')
    {
        return 2;
    }
    else if(symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else return 0;
}
int post()
{
   
    int i,a,b;
    top = -1;
    for(i=0;i<strlen(postfix);i++)
    {
        if(isdigit(postfix[i]))
        {
            push1(postfix[i]-'0');
            //printf("%d", stack2[i]);
        }
        else
        {
            a=pop1();
            b=pop1();
            if(postfix[i]=='+')
            {
                push1(b+a);
            }
            else if(postfix[i]=='-')
            {
                push1(b-a);
            }
            else if(postfix[i]=='*')
            {
                push1(b*a);
            }
            else
            {
                int c = b/a;
                push1(c);
            }
        }
    }
    return pop1();
}
