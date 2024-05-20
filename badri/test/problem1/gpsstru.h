#ifndef GPS_STRU_H //check if gpsstru.h is not defined
#define  GPS_STRU_H//define the headerfile gpsstru.h
#include "header.h"//includes the needed header files

//define a structure to hold the gps data
typedef struct 
{
	char timestamp[30];//time stamp of the gpsdata
	double lattitude;//latitude value
	char lat_dir;//latitude direction (N/S)
	double longitude;//longitude value
	char lon_dir;//longitude direction(E/W)
	double speed;//speed over ground
	double course;//course over ground
	char date[20];//date of the gps data
	double magnetic_variation;//magnetic variation in degrees
	char my_dir;//magnetic variation direction (E/W)
}GPSData;
//function to parse NMEA sentences
int parseNMEA(const char *sentence , GPSData*data);
//hypothetical function for porsche-specific format
int parsePorsche(const char *sentence , GPSData *dat);
//function to update gps data buffer
void updateGPSDataBuffer(GPSData *buffer , GPSData *data);

#endif//end of ifndef header guard
