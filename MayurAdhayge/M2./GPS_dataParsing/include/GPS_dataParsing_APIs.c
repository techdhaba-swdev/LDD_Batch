#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "validation.h"

bool parse(const char *data, GPSData *gps) {
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
    
    int result = sscanf(data, "%7[^,],%9[^,],%c,%f°%f,%c,%f°%f,%c,%f,%f,%6[^,],%f,%3[^*]",
                        message_id, time, &status,
                        &latitude_degrees, &latitude_minutes, &latitude_dir,
                        &longitude_degrees, &longitude_minutes,&longitude_dir,
                        &speed, &course, date,&magnetic_variation, checksum);
                        

    if (validateMessageID(message_id)) {
        strcpy(gps->message_id, message_id);
    } else {
        strcpy(gps->message_id, "-1");
    }

    if (validateTime(time)) {
        strcpy(gps->time, time);
    } else {
        strcpy(gps->time, "-1");
    }

    if (validateStatus(status)) {
        gps->status = status;
    } else {
        gps->status = -1;
    }

    if (validateLatitude(latitude_degrees, latitude_minutes, latitude_dir)) {
        gps->latitude_degrees = latitude_degrees;
        gps->latitude_minutes = latitude_minutes;
        gps->latitude_dir = latitude_dir;
    } else {
        gps->latitude_degrees = -1;
        gps->latitude_minutes = -1;
        gps->latitude_dir = -1;
    }

    if (validateLongitude(longitude_degrees, longitude_minutes, longitude_dir)) {
        gps->longitude_degrees = longitude_degrees;
        gps->longitude_minutes = longitude_minutes;
        gps->longitude_dir = longitude_dir;
    } else {
        gps->longitude_degrees = -1;
        gps->longitude_minutes = -1;
        gps->longitude_dir = -1;
    }

    if (validateSpeed(speed)) {
        gps->speed = speed;
    } else {
        gps->speed = -1;
    }

    if (validateCourse(course)) {
        gps->course = course;
    } else {
        gps->course = -1;
    }

    if (validateDate(date)) {
        strcpy(gps->date, date);
    } else {
        strcpy(gps->date, "-1");
    }

    if (validateMagneticVariation(magnetic_variation)) {
        gps->magnetic_variation = magnetic_variation;     
    } else {
        gps->magnetic_variation = -1;
    }

    if (validateChecksum(checksum)) {
        strcpy(gps->checksum, checksum);
    }

    return true;
}


