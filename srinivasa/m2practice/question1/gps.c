// including the required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gps.h"
// NMEA data parsing function
int parseNMEA(const char* nmea_sentence, GPSData* gpsData) {
    if (nmea_sentence == NULL || gpsData == NULL) {
        return -1; // Error due to null pointer
    }

    char type[6];
    sscanf(nmea_sentence, "$%5[^,]", type);

    if (strcmp(type, "GPRMC") != 0) {
        return -2; // Error for unsupported type
    }

    int ret = sscanf(nmea_sentence,
        "$GPRMC,%*f,%c,%lf,%c,%lf,%c,%lf,%lf,%6s,%lf,%c",
        &gpsData->status,
        &gpsData->latitude,
        &gpsData->lat_direction,
        &gpsData->longitude,
        &gpsData->lon_direction,
        &gpsData->speed,
        &gpsData->course,
        gpsData->date,
        &gpsData->mag_variation,
        &gpsData->mag_var_direction);

    return (ret == 10) ? 0 : -3; // Parsing result
}

// Placeholder for Porsche-specific parsing logic
int parsePorsche(const char* porsche_sentence, GPSData* gpsData) {
    return -1; // Placeholder implementation
}
// Function to identify and parse GPS data format
int parseGPSData(const char* sentence, GPSData* gpsData) {
    if (sentence == NULL || gpsData == NULL) {
        return -1; // Error due to null pointer
    }

    if (strncmp(sentence, "$GPRMC", 6) == 0) {
        return parseNMEA(sentence, gpsData);
    } else {
        return parsePorsche(sentence, gpsData); // Placeholder for other formats
    }
}
// Function to handle each line of GPS data
void processGPSLine(const char* line) {
    GPSData gpsData;
    int result = parseGPSData(line, &gpsData);

    if (result == 0) {
        // Output the parsed data
        printf("Status: %c\n", gpsData.status);
        printf("Latitude: %.4lf %c\n", gpsData.latitude, gpsData.lat_direction);
        printf("Longitude: %.4lf %c\n", gpsData.longitude, gpsData.lon_direction);
        printf("Speed: %.2lf knots\n", gpsData.speed);
        printf("Course: %.2lf degrees\n", gpsData.course);
        printf("Date: %s\n", gpsData.date);
        printf("Magnetic Variation: %.2lf %c\n", gpsData.mag_variation, gpsData.mag_var_direction);
        printf("----------------------------------------\n");
    } else {
        printf("Error parsing GPS data: %d\n", result); // Error handling
    }
}

