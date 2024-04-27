/* this main1.c files used to perfom some caliculator operations 
   like addition, subtraction,multiplication, division with 
   multiple inputs and prints those results .                 */ 

#include"main1.h"  // here we incuded the main1.h header file 

int main()
{     /* we are calling diffrent functions to perform diffrent
         caliculator operations with diffrent values */

        printf("add is %d\n",add2(4, 5));
	printf("add is %d\n",add1(4));
	printf("add is %d\n",add3(4, 5, 6));
	printf("add is %d\n",add4(4, 5, 6, 7));
        printf("sub is %d\n",sub1(14));
	printf("sub is %d\n",sub2(14, 5));
	printf("sub is %d\n",sub3(14, 5, 3));
	printf("sub is %d\n",sub4(14, 5, 3, 2));
	printf("mul is %d\n",mul1(14));
	printf("mul is %d\n",mul2(14, 3));
	printf("mul is %d\n",mul3(14, 3, 2));
	printf("mul is %d\n",mul4(14, 3, 2, 4));
	printf("div is %d\n",div1(200));
	printf("div is %d\n",div2(200, 2));
	printf("div is %d\n",div3(200, 2, 2));
	printf("div is %d\n",div4(200, 2, 2, 2));

        return 0; // indicates the successfull programe termination.
}

