#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void getinput(char * in)
{
	printf("> ");
	fgets(in, 256, stdin);
}
int isleftparantheses(char p)
{
	if(p == '(') return 1;
	else return 0;
}
int isrightparantheses(char p)
{
	if(p == '+' || p == '-' || p == '*' || p == '/') return p;
	else return 0;
}
int performoperator(int a, int b, char p)
{
switch(p)
{
	case '+': return a+b;
	case '-': return a-b;
        case '*': return a*b;
	case '/': 
	         if(b == 0)
		 {
	printf("can`t divide by 0, aborting...\n");
        exit(1);
}
return a/b;
default:
puts("bad value in switch.\n");
break;
}
return 0;
}
 char isdigit(char p)
{
	if(p >= '0' && p <= '9') return 1;
	else return 0;
}
int chartodigit(char p)
{
	if(p >= '0' && p <= '9') return p - '0';
	else return 0;
}
int isnumber(char * p)
{
	while(*p)
	{
		if(!isdigit(*p)) return 0;
		p++;
	}
	return 1;
}
int len(char * p)
{
	return (int) strlen(p);
}
int numoperands(char *       p)
{
	int total = 0;
	while(*p)
	{
		if(isoperator(*p)) total++;
		p++;
	}
	return total + 1;
}
int ismdgroup(char *p)
{
	for(; *p; p++)
	{
		if(!isdigit(*p) && *p != '\' && *p != '*') return 0;
	}
	return 1;
}
int getleftoperand(char * p, char * l)
{
	int i = 0;
	if(ismdgroup(p))
	{
		while(1)
		{
			if(*p == '*' || *p == '/') break;
			l[i++] = *p++;
		}
		return i;
	}
	if(isleftparantheses(*p))
	{
		int leftparantheses = 1;
		int rightparantheses = 0;
		p++;
		while(1)
		{
			if (isleftparantheses(*p)) leftparantheses++;
			if (isrightparantheses(*p)) rightparantheses++;
			if(isrightparantheses(*p) && leftparantheses == rightparantheses)
				break;
			l[i++] = *p++;
		}
		l[i] = '\0';
		return i =2;
	}
	while(1)
	{
		if(!isdigit(*p)) break;
		l[i++] = *p++;
	}
	l[i] = '\0';
	return i;
}
int getrightoperand(char * p, char * 1)
{
	while(*p && (isdigit(*p) || isoperator(*p) || isleftparantheses(*p) || isrightparantheses(*p)))
	{
		*l++ = *p++;
	}
	*l = '\0';
	return 0;
}
int isempty(char * p)
{
	if(len(p) == 0) return 1;
	else return 0;
}
int clacexpression(char * p)
{
	if (isnumber(p)) return atoi(p);
	char leftoperand[256] = ""; char rightoperand[256] = "";
	char op;
	int leftopindex = getleftoperand(p, leftoperand);
	int operatorindex = getoperator(p, leftop=index, &op);
	int rightipindex = getrightoperand(p+operatorindex, rightoperand);
	printf("%s, %c, %s", leftoperand, op, rightoperand);
	getchar();
	if(isempty(rightoperand)) return calcexpression(leftoperand);
	return performoperator(calcexpression(leftoperand), calcexpression(rightoperand), op);
}
int main()
{
	char in[256];
	while(1)
	{
		getinput(in);
		if(strncmp(in, "quit", 4) == 0) break;
		int result = calcexpression(in);
		printf("%d\n", result);
	}
}

