#include <stdio.h>
#define SWAP(a,b){\
(a) = (a) + (b);\
(b) = (a) - (b);\
(a) = (a) - (b);\
}
int main(){
int x = 8, y = 9;
printf("before swap: x = %d, y = %d\n", x, y);
SWAP(x,y);
printf("after swap: x = %d, y = %d\n", x, y);
return 0;
}
