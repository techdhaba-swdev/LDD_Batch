#include<stdio.h>
#include<string.h>



union type {

	char a;
	char b;
	char c;
	char d; 
} ;



        union type type1;
        type1.a = 'D';
	printf("Vslue of a: %c\n", type1.a);
        type1.b = 'H';
        printf("Vslue of a: %c\n", type1.b);


        type1.c = 'R';
	printf("Vslue of a: %c\n", type1.c);




        type1.d = 'I';
	 printf("Vslue of a: %c\n", type1.d);



char arr[4] = {'A','B','C','D'};

printf("Value of arr: %c\n", arr[4]);

}


