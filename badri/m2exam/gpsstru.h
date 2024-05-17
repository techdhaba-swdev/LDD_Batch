#ifndef GPS_STRU_H
#define  GPS_STRU_H
#include "header.h"
typedef struct 
{
	char timestamp[30];
	double lattitude;
	char lat_dir;
	double longitude;
	char lon_dir;
	double speed;
	double course;
	char date[20];
	double magnetic_variation;
	char my_dir;
}GPSData;

int parseNMEA(const char *sentence , GPSData*data);
int parsePorsche(const char *sentence , GPSData *dat);
void updateGPSDataBuffer(GPSData *buffer , GPSData *data);

#endif
