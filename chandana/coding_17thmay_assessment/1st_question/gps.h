#ifndef GPS_H  //header files file secure code
#define GPS_H 
#include <stdio.h> //header files for standard input output file
#include <string.h>//heder file for string functions

// Structure to hold GPS data
typedef struct {
    char time[11];         // Time of the GPS 
    char status;           // Status 
    char latitude[11];     // Latitude
    char lat_direction;    // Latitude direction
    char longitude[12];    // Longitude 
    char lon_direction;    // Longitude 
    char speed[6];         // Speed 
    char course[6];        // Course
    char date[7];          // Date )
} GPSData;

// Function to parse GPS data
int parse(const char* sentence, GPSData* gps_data);

#endif // GPS_H
