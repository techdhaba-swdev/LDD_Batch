#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "gdp.h"

int parse_data(char *data, GDPData *gdp){
	int ret = sscanf(data,"$GPRMC,%9[^,],%c,%lf,%c,%lf,%c,%lf,%lf,%6[^,],%lf,%c*%3s",
			gdp->ts,
			&gdp->status,
			&gdp->lat,
			&gdp->latdir,
			&gdp->lt,
			&gdp->long_dir,
			&gdp->sp,
			&gdp->cs,
			gdp->data,
			&gdp->variation,
			&gdp->var_dir,
			gdp->checksum);
	gdp->lat=(int)(gdp->lat/100)+fmod(gdp->lat,100)/60;
	gdp->lt=(int)(gdp->lt/100)+fmod(gdp->lt,100)/60;

	if(gdp->lat_dir == 'S')
		gdp->lat = -gdp->lat;
	if(gdp->long_dir == 'W')
                gdp->lt = -gdp->lt;
	return ret == 12 ? 0 : -1;
}
int parse_por(char *data, GDPData *gdp){
	int ret = sscanf(data,"$PORSCH,%9[^,],%c,%lf,%c,%lf,%c,%lf,%lf,%6[^,],%lf,%c*%3s",
                        gdp->ts,
                        &gdp->status,
                        &gdp->lat,
                        &gdp->latdir,
                        &gdp->lt,
                        &gdp->long_dir,
                        &gdp->sp,
                        &gdp->cs,
                        gdp->data,
                        &gdp->variation,
                        &gdp->var_dir,
                        gdp->checksum);
	gdp->lat=(int)(gdp->lat/100)+fmod(gdp->lat,100)/60;
        gdp->lt=(int)(gdp->lt/100)+fmod(gdp->lt,100)/60;

        if(gdp->lat_dir == 'S')
                gdp->lat = -gdp->lat;
        if(gdp->long_dir == 'W')
                gdp->lt = -gdp->lt;
        return ret == 12 ? 0 : -1;
}
void update(GDPData *buffer,int *buffersize, GDPData *newdata){
	if(*buffersize < BUFFER_SIZE){
		buffer[*buffersize] = *newdata;
		(*buffersize)++;
	}
	else{
printf("Unable to add new data to buffeer\n");
	}
}
void print_GDPData(const GDPData *gdp);
printf("ts:%s\n",gdp->ts);
printf("status:%c\n",gdp->status);
printf("lat:%.6f %c\n",gdp->lat,gdp->lat_dir);
printf("lt:%.6f %c\n",gdp->lt,gdp->long_dir);
printf("sp:%.2f \n",gdp->sp);
printf("cs:%.2fdegrees\n",gdp->cs);
printf("data:%sdate\n",gdp->data);
printf("variation:%s\n",gdp->variation,gdp->var_dir);
printf("checksum:%s\n",gdp->checksum);
}

