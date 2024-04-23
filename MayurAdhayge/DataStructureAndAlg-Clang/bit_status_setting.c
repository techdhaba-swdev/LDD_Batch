#include <stdio.h>

int main()
{
    int x[]={1,2,3,4,5,6,7,8};
    int y[]={8,7,6,5,4,3,2,1};
    unsigned char status=0;
    for(int i=0;i<8;i++)
    {
      if (x[i] > y[i])
      {
       status=status | 1<<i;   
      }
    }
    printf("%d",status);

    for(int j=0;j<8;j++)
    {
        if( status & 1<<j)
        {
          printf("\ntrue");
        }
        else
        {
          printf("\nfalse");  
        }
        
    }

    return 0;
}
