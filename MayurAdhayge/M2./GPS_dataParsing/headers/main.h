#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
typedef struct {
    char message_id[8];
    char time[12]; 
    char status;
    float latitude_degrees;
    float latitude_minutes;
    char latitude_dir;
    float longitude_degrees;
    float longitude_minutes;
    char longitude_dir;
    float speed;
    float course;
    char date[7];
    float magnetic_variation;
    char checksum[4];
} GPSData;


#endif 

