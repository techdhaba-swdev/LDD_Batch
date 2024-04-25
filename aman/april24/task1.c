#include<stdio.h>
int main(){
	int secretNumber, guess;
	secretNumber = 50;
	printf("guess the secret number: ");
	scanf("%d\n", &guess);
	if(guess == secretNumber){
		printf("you have guessed the secret number.\n");
	}
	else{

		printf("no, that's not the secret number.\n");
	}
	return 0;
}
