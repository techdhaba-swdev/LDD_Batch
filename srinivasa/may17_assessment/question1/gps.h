#ifndef GPS_H
#define GPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NMEA_LEN 100

typedef struct {
    double latitude;
    double longitude;
    double altitude;
    char latitudeDirection;
    char longitudeDirection;
    int satellites;
    double hdop; // Horizontal Dilution of Precision
} GPSData;

void parseGPSData(const char *nmeaSentence, GPSData *data);

#endif // GPS_H
