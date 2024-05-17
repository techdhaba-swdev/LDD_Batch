#include<stdio.h>
#include<string.h>
#include "gdp.h"
int main(){
	GDPdata buffer[BUFFER_SIZE];
	int buffersize = 0;
	char dataa[256];

	const char *nmeaDate = "$GPRMC 0800000.00,A.40.7128-N,74.0059-W,0.00,0.0,170524,000.0,M,N*77";
	const char *porse="$PORSCH 0800000.00,A.40.7128-N,74.0059-W,0.00,0.0,170524,000.0,M,N*74";
	GDPData gdp;

	strcpy(data,nmeDate);
	if(strncmp(dataa,"$GPRMC",6)==0){
		if(parse_data(dataa,&gdp)==0)
		{
			updateBuffer(buffer,&buffersize,&gdp);
			printGDPData(&gdp);
		}
		else{
			printf("failed \n");
		}
	}
	else if(strncmp(dataa,"$PORSCH",7)==0){
		updateBuffer(buffer,&buffersize,&gdp);
                        printGDPData(&gdp);
	
	else
	{
		 printf("failed \n");
                }
        }
else{
	printf("unknow data \n");
}
return 0;
}
