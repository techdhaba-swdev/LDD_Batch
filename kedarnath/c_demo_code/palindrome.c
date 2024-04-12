#include<stdio.h>
#include<string.h>
int palindrome(char *str){
	int len=strlen(str);
	printf("length is %d\n",len);
	char str2[len];
	strcpy(str2,str);
	char str3[len];
	int j=0;
	for(int i=len-1;i>=0;i--){
		str3[j++]=str[i];
	}

	str3[j]='\0';
	printf("%s %s %d %d \n",str,str3,strlen(str),strlen(str3));
	printf("%d\n",str2==str3);

	if(str2 == str3){
		printf("hii\n");
		return 1;
	}
	
	return 0;

}

int main(){

	char str[20];
	printf("enter the string\n");
	scanf ("%s",str);
	int result=palindrome(str);
	printf("result is %d\n",result);
	if(result==1){
		printf("string is palindrome\n");
	}else{
		printf("string is not palindrome\n");
	}
	if("hello"=="hello"){
		printf("hello\n");
	}else{
		printf("byy\n");
	}

	return 0;

}

