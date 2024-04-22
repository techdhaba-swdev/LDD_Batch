#include<stdio.h>

union word
{
char ch1;
char ch2;
char ch3;
char ch4;
char ch[5];
};

int main()
{
int i;
//union word objWord={.ch1='a',.ch2='b',.ch3='c',.ch4='d',.ch={'c','d','e','f','\0'}};

union word objWord;
for(i=0;i<4;i++)
{
objWord.ch[i]= (char) i;
}
objWord.ch[i+1]='\0';
//objWord.ch={'c','d','e','f','\0'};
objWord.ch1='a';objWord.ch2='b';objWord.ch3='c';objWord.ch4='d';


printf("%c ",objWord.ch1);
printf("%c ",objWord.ch2);
printf("%c ",objWord.ch3);
printf("%c ",objWord.ch4);
printf("\n%s\n",objWord.ch);



return 0;
}

